#ifndef __COM_H
#define __COM_H

#include <string>
#include <iostream>
#include "SerialPort.h"
#include <memory>
#include "rio.h"

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
		//fd = -1;
		
		rio_pack.rio_fd = -1;
		rio_pack.rio_cnt = 0;
		rio_pack.rio_bufptr = rio_pack.rio_buf;
	}
	Com(std::string nme) : name(nme)
	{
		//这句代码增加了 COM 和 SerialPort 的耦合性
		//port->setPortAttr(9600, 0, EIGHT, ONE, N);
		//fd = -1;
		
		rio_pack.rio_fd = -1;
	}
	
	bool OpenCom();
	bool bind();
	int recv_data(unsigned char *buf, size_t len);
	int recv_OneByte(unsigned char *buf);
	
private:
	int fd;
	
	rio_t rio_pack;
	std::shared_ptr<Port> port;
};

#endif