#ifndef __WAIT_LEN_STATE_H
#define __WAIT_LEN_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitLenState : public State
{
public:
	WaitLenState(Usart_FSM *pfsm);
	
	bool sendSynChar();
	bool sendLength();
	bool sendCmd();
	bool sendExtra();
	bool sendValid();
	
private:
	std::shared_ptr<Usart_FSM> usartFsm; 
};

#endif