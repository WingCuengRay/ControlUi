#ifndef __IDLE_STATE_H
#define __IDLE_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class IdleState : public State
{
public:
	IdleState(shared_ptr<Usart_FSM> pfsm) : usartFsm(pfsm)
	{}
	
	bool sendHead()
	{
		char ch;
		if(usartFsm.com.recv_data(&ch, 1) == 1)
		{
			if(ch == usartFsm.frame.head)
			{
				usartFsm.setState(usartFsm->getWaitLenState());
				return true;
			}
			else
			{
				usartFsm.setState(usartFsm->getIdleState());
				return false;
			}
			
		}
	}
	bool sendLength()
	{
		return false;
	}
	
	bool sendCmd()
	{
		return false;
	}
	
	bool sendExtra()
	{
		return false;
	}
	
	bool sendValid()
	{
		return false;
	}
	
	bool sendTail()
	{
		return false;
	}
	
	
private:
	shared_ptr<Usart_FSM> usartFsm; 
};

#endif