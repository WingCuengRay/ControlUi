#ifndef __WAIT_LEN_STATE_H
#define __WAIT_LEN_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitLenState : public State
{
public:
	WaitLenState(Usart_FSM *pfsm);
	
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