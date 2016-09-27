#include "SerialPort.h"
#include "com.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	SerialPort port1(9600);
	Com com1("/dev/ttyS0", make_shared<SerialPort>(port1));
	
	if(com1.OpenCom() == false)
	{
		cout << "OpenCom error." << endl;
		cout << com1.name << endl;
		return 0;
	}
	if(!com1.bind())
	{
		cout << "Bind USART error." << endl;
		return 0;
	}
	
	char buf[512];
	int ret;
	if((ret=com1.recv_data(buf, 512)) >= 0)
	{
		buf[ret] = 0;
		cout << "buf: " << buf << endl;
	}
	else
		cout << "recv_data error." << endl;
	
	return 0;
	
}