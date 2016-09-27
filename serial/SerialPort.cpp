#include "SerialPort.h"

bool SerialPort::setConfiguration(int fd)
{
	struct termios options;
	const int speedBin_arr[] = { B38400, B19200, B9600, B4800, 
								 B2400, B1200, B300,B38400, B19200, 
								 B9600, B4800, B2400, B1200, B300 };
	int speedDec_arr[] = {38400,  19200,  9600,  4800,  2400,  1200,  
						 300, 8400, 19200, 9600, 4800, 2400, 1200, 300};
	
	if(tcgetattr(fd, &options) == -1)
	{
		perror("GetAttr error");
		return false;
	}
	
	for(int i=0; i<sizeof(speedDec_arr)/sizeof(int); i++)
	{
		if(baud == speedDec_arr[i])
		{
			cfsetispeed(&options, speedBin_arr[i]);
			cfsetospeed(&options, speedBin_arr[i]);
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
	   case 5:
			options.c_cflag |= CS5;
			break;
	   case 6:
			 options.c_cflag |= CS6;
			 break;
	   case 7:    
			 options.c_cflag |= CS7;
			 break;
	   case 8:    
			 options.c_cflag |= CS8;
			 break;  
	   default:   
			 fprintf(stderr,"Unsupported data size/n");
			 return (false); 
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
				 return (false); 
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
			   return (false);
	}
   
	options.c_oflag = 0;
	options.c_lflag = 0;
   
   
	//如果发生数据溢出，接收数据，但是不再读取
	tcflush(fd, TCIFLUSH);
   
	//激活配置 (将修改后的termios数据设置到串口中）
	if (tcsetattr(fd,TCSANOW,&options) != 0)  
	{
		perror("com set error!/n");  
		return (false); 
	}
	
	return true;
}
	