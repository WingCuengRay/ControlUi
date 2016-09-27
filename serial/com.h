#ifndef __COM_H
#define __COM_H

#include <string>
#include <iostream>
#include "SerialPort.h"

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
	
	Com(const std::string &nme, const Port &p) : name(nme), port(p)
	{
		fd = -1;
	}
	Com(std::string nme) : name(nme)
	{
		port.setPortAttr(9600, 0, EIGHT, ONE, N);
		fd = -1;
	}
	
	bool OpenCom();
	bool bind();
	int recv_data(char *buf, size_t len);
	
private:
	int fd;
	Port port;
};

#endif