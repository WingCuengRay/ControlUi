#ifndef __WAIT_CMD_STATE_H
#define __WAIT_CMD_STATE_H

#include "State.h"
#include "Usart_FSM.h"

class WaitCmdState : public State
{
public:
	WaitCmdState(Usart_FSM *pfsm);
	bool sendSynChar();
	
	bool sendLength();
	bool sendCmd();
	
	bool sendExtra();
	bool sendValid();
	
private:
	std::shared_ptr<Usart_FSM> usartFsm; 
};

#endif