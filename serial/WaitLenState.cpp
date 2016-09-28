#include "WaitLenState.h"

WaitLenState::WaitLenState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

bool WaitLenState::sendHead()
{
	return false;	
}

bool WaitLenState::sendLength()
{
	char ch;
	if(usartFsm->com.recv_data(&ch, 1) == 1)
	{
		usartFsm->frame.length = ch;
		usartFsm->setState(usartFsm->getWaitCmdState());
		return true;
	}
	else
	{
		usartFsm->setState(usartFsm->getIdleState());
		return false;
	}		
}

bool WaitLenState::sendCmd()
{
	return false;
}

bool WaitLenState::sendExtra()
{
	return false;
}

bool WaitLenState::sendValid()
{
	return false;
}

bool WaitLenState::sendTail()
{
	return false;
}
