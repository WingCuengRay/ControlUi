#ifndef __WAIT_VALID_STATE_H
#define __WAIT_VALID_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitValidState : public State
{
public:
	WaitValidState(Usart_FSM *pfsm);
	bool sendSynChar();
	bool sendLength();
	bool sendCmd();
	bool sendExtra();
	bool sendValid();

private:
	std::shared_ptr<Usart_FSM> usartFsm; 
};

#endif