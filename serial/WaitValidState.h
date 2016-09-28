#ifndef __WAIT_VALID_STATE_H
#define __WAIT_VALID_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitValidState : public State
{
public:
	WaitValidState(shared_ptr<Usart_FSM> pfsm) : usartFsm(pfsm)
	{}
	
	bool sendHead()
	{
		return false;	
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
		char ch;
		if(usartFsm.com.recv_data(&ch, 1) == 1)
		{
			usartFsm.frame.valid = ch;
			if(usartFsm.frame.Valid() == true)
			{
				usartFsm.setState(usartFsm->getWaitTailState());
				return true;
			}
			else
			{
				usartFsm.setState(usartFsm->getIdleState());
				return true;
			}
		}
		else
		{
			usartFsm.setState(usartFsm->getIdleState());
			return false;
		}
	}
	
	bool sendTail()
	{
		return false;
	}
	
	
private:
	shared_ptr<Usart_FSM> usartFsm; 
};

#endif