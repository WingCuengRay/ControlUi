#ifndef __WAIT_CMD_STATE_H
#define __WAIT_CMD_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitCmdState : public State
{
public:
	WaitCmdState(Usart_FSM *pfsm);
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