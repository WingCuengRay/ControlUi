#include "com.h"

bool Com::OpenCom()
{
	int ret = open(name.c_str(), O_RDWR|O_NOCTTY);
	if(ret == -1)
		return false;
	//rio_pack.rio_fd = ret;
	rio_readinitb(&rio_pack, ret);
	
	return true;
}

bool Com::bind()
{
	if(rio_pack.rio_fd == -1)
		return false;
	return port->setConfiguration(rio_pack.rio_fd);
}

int Com::recv_data(unsigned char *buf, size_t len)
{
	//int ret = read(fd, buf, len);
	int ret = rio_readnb(&rio_pack, buf, len);

	return ret;
}

using namespace std;
int Com::recv_OneByte(unsigned char *buf)
{
	int ret = rio_readnb(&rio_pack, buf, 1);
	if(ret == 1 && *buf==0x7d)
	{
		ret = rio_readnb(&rio_pack, buf, 1);
		if(ret == 1)
			*buf ^= 0x20;		//遇到转义字符 '7d' 将其后面第一个字符的第六位取反
	}
	//cout << "hex: " << hex << (int)(*buf) << endl; 
	
	return ret;
}
