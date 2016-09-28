#ifndef __IDLE_STATE_H
#define __IDLE_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class IdleState : public State
{
public:
	IdleState(Usart_FSM* pfsm);
	
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