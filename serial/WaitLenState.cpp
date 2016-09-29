#include "WaitLenState.h"

WaitLenState::WaitLenState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

bool WaitLenState::sendSynChar()
{
	//usartFsm->setState(usartFsm->getIdleState());
	return false;
}

bool WaitLenState::sendLength()
{
	char ch;
	
	//任何数字都可能成为长度（包括同步符代表的数字），只要不为 0 即进入对命令的接收
	if(usartFsm->com.recv_data(&ch, 1)==1 && ch!=0)
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
