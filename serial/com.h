#ifndef __COM_H
#define __COM_H

#include <string>
#include <iostream>
#include "SerialPort.h"
#include <memory>

extern "C"
{
	#include <fcntl.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
};

class Com
{
public:
	std::string name;
	
	Com(const std::string &nme, std::shared_ptr<Port> p) : name(nme), port(p)
	{
		fd = -1;
	}
	Com(std::string nme) : name(nme)
	{
		//这句代码增加了 COM 和 SerialPort 的耦合性
		//port->setPortAttr(9600, 0, EIGHT, ONE, N);
		fd = -1;
	}
	
	bool OpenCom();
	bool bind();
	int recv_data(char *buf, size_t len);
	int recv_OneByte(char *buf);
	
private:
	int fd;
	std::shared_ptr<Port> port;
};

#endif