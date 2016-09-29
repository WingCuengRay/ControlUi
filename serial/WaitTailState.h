#ifndef __WAIT_TAIL_STATE_H
#define __WAIT_TAIL_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitTailState : public State
{
public:
	WaitTailState(Usart_FSM *pfsm);
	
	bool sendSynChar();
	bool sendLength();
	bool sendCmd();
	bool sendExtra();
	bool sendValid();
	
private:
	std::shared_ptr<Usart_FSM> usartFsm; 
};

#endif