#ifndef __STATE_H
#define __STATE_H

class State
{
public:
	virtual bool sendHead() = 0;
	virtual bool sendTail() = 0;
	virtual bool sendCmd() = 0;
	virtual bool sendValid() = 0;
	virtual bool sendExtra() = 0;
	virtual bool sendLength() = 0;
};

#endif