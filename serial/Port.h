#ifndef __PROTOCOL_H
#define __PROTOCOL_H


class Port
{
public:
	virtual bool setConfiguration(int fd) = 0;
};

#endif