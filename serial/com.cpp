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

	return ret;
}

int Com::recv_OneByte(unsigned char *buf)
{
	int ret = read(fd, buf, 1);
	if(ret == 1 && *buf==0x7d)
	{
		ret = read(fd, buf, 1);
		*buf ^= 0x20;		//遇到转义字符 '7d' 将其后面第一个字符的第六位取反
	}
	
	return ret;
}
