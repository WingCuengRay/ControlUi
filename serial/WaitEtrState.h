#ifndef __WAIT_ETR_STATE_H
#define __WAIT_ETR_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitEtrState : public State
{
public:
	WaitEtrState(Usart_FSM* pfsm);
	
	bool sendSynChar();
	
	bool sendLength();
	bool sendCmd();
	
	bool sendExtra();
	bool sendValid();
	
	
private:
	std::shared_ptr<Usart_FSM> usartFsm; 
};

#endif