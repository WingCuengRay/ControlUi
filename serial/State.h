#ifndef __STATE_H
#define __STATE_H

class State
{
	virtual bool sendHead() = 0;
	virtual bool sendTail();
	virtual bool sendCmd();
	virtual bool sendValid();
	virtual bool sendExtra();
	virtual bool sendLength();
}

#endif