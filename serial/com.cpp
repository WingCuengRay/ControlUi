#include "com.h"

bool Com::OpenCom()
{
	int ret = open(name.c_str(), O_RDWR|O_NOCTTY);
	if(ret == -1)
		return false;
	fd = ret;
	
	return true;
}

bool Com::bind()
{
	if(fd == -1)
		return false;
	return port->setConfiguration(fd);
}

int Com::recv_data(char *buf, size_t len)
{
	int ret = read(fd, buf, len);
//	if(ret >= 0)
//		buf[ret] = 0;
	return ret;
}
