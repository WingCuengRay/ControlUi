#ifndef __WAIT_ETR_STATE_H
#define __WAIT_ETR_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitEtrState : public State
{
public:
	WaitEtrState(Usart_FSM* pfsm);
	
	bool sendHead();
	
	bool sendLength();
	bool sendCmd();
	
	bool sendExtra();
	bool sendValid();
	
	bool sendTail();
	
	
private:
	std::shared_ptr<Usart_FSM> usartFsm; 
};

#endif