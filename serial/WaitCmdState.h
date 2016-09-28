#ifndef __WAIT_CMD_STATE_H
#define __WAIT_CMD_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitCmdState : public State
{
public:
	WaitCmdState(shared_ptr<Usart_FSM> pfsm) : usartFsm(pfsm)
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
		char ch;
		if(usartFsm.com.recv_data(&ch, 1) == 1)
		{
			usartFsm.frame.cmd = ch;
			usartFsm.setState(usartFsm->getWaitEtrState());
			
			return true;
		}
		else
		{
			usartFsm.setState(usartFsm->getIdleState());
			return false;
		}
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