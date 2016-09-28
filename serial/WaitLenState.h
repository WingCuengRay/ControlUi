#ifndef __WAIT_LEN_STATE_H
#define __WAIT_LEN_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitLenState : public State
{
public:
	WaitLenState(shared_ptr<Usart_FSM> pfsm) : usartFsm(pfsm)
	{}
	
	bool sendHead()
	{
		return false;	
	}
	
	bool sendLength()
	{
		char ch;
		if(usartFsm.com.recv_data(&ch, 1) == 1)
		{
			usartFsm.frame.length = ch;
			usartFsm.setState(usartFsm->getWaitCmdState());
			return true;
		}
		else
		{
			usartFsm.setState(usartFsm->getIdleState());
			return false;
		}		
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