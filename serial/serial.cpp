#include <stdio.h>
#include <termios.h>
#include <iostream>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FALSE 0
#define TRUE 1
#define UART_DEVICE "/dev/ttyS0"

int UART_Open(char *dir);
int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity);
int UART0_Init(int fd, int speed,int flow_ctrlint,int databits,int stopbits,int parity);
int UART_Send(int fd, char *send_buf,int data_len);
int UART_Recv(int fd, char *rcv_buf,int data_len);

using namespace std;

int main(void)
{
	int fd = UART_Open(UART_DEVICE);
	
	if (UART0_Set(fd,9600,0,8,1,'N') == FALSE)
    {         
		cout << "UART0_Set False\n";
        return FALSE;
    }
	
	//UART_Send(fd, "Hello World", 10);
	char str[100];
	/*
	int ret = UART_Recv(fd, str, 100);
	if(ret > 0)
	{
		str[ret] = 0;
		cout << "str:" << str << endl;
	}
	*/
	int ret = read(fd, str, 100);
	if(ret > 0)
	{
		str[ret] = 0;
		cout << "str:" << str << endl;
	}
	else
	{
		//perror("ret <= 0\n");
	}
		//cout << "Error: ret == " << ret << endl;
	
	return 0;
}

int UART_Open(char *dir)
{
	//可读可写; 不会成为进程的控制终端；非阻塞模式，不会 wait
	int fd = open(dir, O_RDWR|O_NOCTTY);
	if(fd == -1)
	{
		cout << "Can't open " << dir << endl;
		return 0;
	}

		
	printf("fd = %d\n", fd);
	return fd;
}


int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity)
{
   
    int   i;
    int   status;
    int   speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300,
          B38400, B19200, B9600, B4800, B2400, B1200, B300 };
     int   name_arr[] = {38400,  19200,  9600,  4800,  2400,  1200,  300,      38400,  19200,  9600, 4800, 2400, 1200,  300 };
         
    struct termios options;
   
    /*tcgetattr(fd,&options)得到与fd指向对象的相关参数，并将它们保存于options,该函数,还可以测试配置是否正确，该串口是否可用等。若调用成功，函数返回值为0，若调用失败，函数返回值为1.
    */
    if  ( tcgetattr( fd,&options)  ==  -1)
       {
          perror("SetupSerial 1");    
          return(FALSE); 
       }
  
    //设置串口输入波特率和输出波特率
    for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++)
    {
        if  (speed == name_arr[i])
        {       
            cfsetispeed(&options, speed_arr[i]); 
            cfsetospeed(&options, speed_arr[i]);  
        }
    }     
   
    //修改控制模式，保证程序不会占用串口
    options.c_cflag |= CLOCAL;
    //修改控制模式，使得能够从串口中读取输入数据
    options.c_cflag |= CREAD;
  
    //设置数据流控制
    switch(flow_ctrl)
    {
      
       case 0 ://不使用流控制
              options.c_cflag &= ~CRTSCTS;
              break;   
      
       case 1 ://使用硬件流控制
              options.c_cflag |= CRTSCTS;
              break;
       case 2 ://使用软件流控制
              options.c_cflag |= IXON | IXOFF | IXANY;
              break;
    }
    //设置数据位
    options.c_cflag &= ~CSIZE; //屏蔽其他标志位
    switch (databits)
    {  
       case 5    :
                     options.c_cflag |= CS5;
                     break;
       case 6    :
                     options.c_cflag |= CS6;
                     break;
       case 7    :    
                 options.c_cflag |= CS7;
                 break;
       case 8:    
                 options.c_cflag |= CS8;
                 break;  
       default:   
                 fprintf(stderr,"Unsupported data size/n");
                 return (FALSE); 
    }
    //设置校验位
    switch (parity)
    {  
       case 'n':
       case 'N': //无奇偶校验位。
                 options.c_cflag &= ~PARENB; 
                 options.c_iflag &= ~INPCK;    
                 break; 
       case 'o':  
       case 'O'://设置为奇校验    
                 options.c_cflag |= (PARODD | PARENB); 
                 options.c_iflag |= INPCK;             
                 break; 
       case 'e': 
       case 'E'://设置为偶校验  
                 options.c_cflag |= PARENB;       
                 options.c_cflag &= ~PARODD;       
                 options.c_iflag |= INPCK;       
                 break;
       case 's':
       case 'S': //设置为空格 
                 options.c_cflag &= ~PARENB;
                 options.c_cflag &= ~CSTOPB;
                 break; 
        default:  
                 fprintf(stderr,"Unsupported parity/n");   
                 return (FALSE); 
    } 
    // 设置停止位 
    switch (stopbits)
    {  
       case 1:   
                 options.c_cflag &= ~CSTOPB; 
                 break; 
       case 2:   
                 options.c_cflag |= CSTOPB; 
                         break;
       default:   
                       fprintf(stderr,"Unsupported stop bits/n"); 
                       return (FALSE);
    }
   
    //修改输出模式，原始数据输出
    options.c_oflag &= ~OPOST;
   
    //设置等待时间和最小接收字符
    options.c_cc[VTIME] = 1; /* 读取一个字符等待1*(1/10)s */  
    options.c_cc[VMIN] = 1; /* 读取字符的最少个数为1 */
   
    //如果发生数据溢出，接收数据，但是不再读取
    tcflush(fd,TCIFLUSH);
   
    //激活配置 (将修改后的termios数据设置到串口中）
    if (tcsetattr(fd,TCSANOW,&options) != 0)  
    {
               perror("com set error!/n");  
       return (FALSE); 
    }
    return (TRUE); 
}
/*******************************************************************
* 名称：        UART0_Init()
* 功能：        串口初始化
* 入口参数：    fd        文件描述符   
*               speed     串口速度
*               flow_ctrl   数据流控制
*               databits    数据位   取值为 7 或者8
*               stopbits   停止位   取值为 1 或者2
*               parity     效验类型 取值为N,E,O,,S                    
* 出口参数：    正确返回为1，错误返回为0
*******************************************************************/
int UART0_Init(int fd, int speed,int flow_ctrlint,int databits,int stopbits,int parity)
{
    int err;
    //设置串口数据帧格式
    if (UART0_Set(fd,115200,0,8,1,'N') == FALSE)
    {                                                     
        return FALSE;
    }
    else
    {
        return  TRUE;
    }
}

int UART_Recv(int fd, char *rcv_buf,int data_len)
{
    int len,fs_sel;
    fd_set fs_read;
    
    struct timeval time;
    
    FD_ZERO(&fs_read);
    FD_SET(fd,&fs_read);
    
    time.tv_sec = 10;
    time.tv_usec = 0;
    
    fs_sel = select(fd+1,&fs_read,NULL,NULL,&time);
    if(fs_sel)
	{
	    len = read(fd,rcv_buf,data_len);	
	    return len;
    } 
	else 
	{
		return FALSE;
	}	
}


int UART_Send(int fd, char *send_buf,int data_len)
{
    int ret;
    
    ret = write(fd,send_buf,data_len);
    if (data_len == ret )
	{	
	    return ret;
    } 
	else 
	{    
	    tcflush(fd,TCOFLUSH);    
	    return FALSE;
    }
    
}
