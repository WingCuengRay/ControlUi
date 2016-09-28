#include "WaitTailState.h"

WaitTailState::WaitTailState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

bool WaitTailState::sendHead()
{
	return false;	
}

bool WaitTailState::sendLength()
{
	return false;
}

bool WaitTailState::sendCmd()
{
	return false;
}

bool WaitTailState::sendExtra()
{
	return false;
}

bool WaitTailState::sendValid()
{
	return false;
}

bool WaitTailState::sendTail()
{
	char ch;
	if(usartFsm->com.recv_data(&ch, 1) == 1)
	{
		if(ch == usartFsm->frame.tail && usartFsm->frame.Valid()==true)
		{
			usartFsm->setState(usartFsm->getIdleState());
			return true;
		}	
	}

	usartFsm->setState(usartFsm->getIdleState());
	return false;
}