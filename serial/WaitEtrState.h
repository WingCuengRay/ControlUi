#ifndef __WAIT_ETR_STATE_H
#define __WAIT_ETR_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitEtrState : public State
{
public:
	WaitEtrState(shared_ptr<Usart_FSM> pfsm) : usartFsm(pfsm)
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
		char ch;
		string tmp;
		
		for(int i=length-1; i!=0; )
		{
			if(usartFsm.com.recv_data(&ch, 1) == 1)
			{
				tmp.push_back(ch);
				i--;
			}
			else
			{
				usartFsm.setState(usartFsm->getIdleState());
				return false;
			}
		}
		usartFsm.frame.dat.etr = tmp;
		usartFsm.setState(usartFsm->getWaitValidState());
		
		return true;
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