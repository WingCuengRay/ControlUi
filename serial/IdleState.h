#ifndef __IDLE_STATE_H
#define __IDLE_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class IdleState : public State
{
public:
	IdleState(Usart_FSM* pfsm);
	
	bool sendSynChar();
	bool sendLength();
	bool sendCmd();
	bool sendExtra();
	bool sendValid();
	
private:
	std::shared_ptr<Usart_FSM> usartFsm; 
};

#endif