#include "WaitValidState.h"


WaitValidState::WaitValidState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

bool WaitValidState::sendHead()
{
	return false;	
}

bool WaitValidState::sendLength()
{
	return false;
}

bool WaitValidState::sendCmd()
{
	return false;
}

bool WaitValidState::sendExtra()
{
	return false;
}

bool WaitValidState::sendValid()
{
	char ch;
	if(usartFsm->com.recv_data(&ch, 1) == 1)
	{
		usartFsm->frame.valid = ch;
		
		usartFsm->setState(usartFsm->getWaitTailState());
		return true;
	}
	else
	{
		usartFsm->setState(usartFsm->getIdleState());
		return false;
	}
}

bool WaitValidState::sendTail()
{
	return false;
}

