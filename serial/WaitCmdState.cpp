#include "WaitCmdState.h"
#include "Usart_FSM.h"

WaitCmdState::WaitCmdState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

bool WaitCmdState::sendHead()
{
	return false;	
}

bool WaitCmdState::sendLength()
{
	return false;
}

bool WaitCmdState::sendCmd()
{
	char ch;
	if(usartFsm->com.recv_data(&ch, 1) == 1)
	{
		usartFsm->frame.dat.cmd = ch;
		usartFsm->setState(usartFsm->getWaitEtrState());
		
		return true;
	}
	else
	{
		usartFsm->setState(usartFsm->getIdleState());
		return false;
	}
}

bool WaitCmdState::sendExtra()
{
	return false;
}

bool WaitCmdState::sendValid()
{
	return false;
}

bool WaitCmdState::sendTail()
{
	return false;
}
