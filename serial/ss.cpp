#include <string>
#include <iostream>

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
	
	Com(std::string nme, const SerialPort &p) : name(nme), port(p)
	{
		fd = -1;
	}
	Com(std::string nme) : name(nme)
	{
		port.setPortAttr(9600);
		fd = -1;
	}
	
	bool OpenCom()
	{
		int ret = open(name, O_RDWR|O_NOCTTY|O_NDELAY);
		if(ret == -1)
			return FALSE;
		fd = ret;
	}
	
	bool bindUART()
	{
		if(fd == -1)
			return FALSE;
		return port.bindCom(fd);
	}
	
	
private:
	int fd;
	Port port;
};