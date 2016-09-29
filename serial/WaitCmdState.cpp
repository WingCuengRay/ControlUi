#include "WaitCmdState.h"
#include "Usart_FSM.h"

WaitCmdState::WaitCmdState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

bool WaitCmdState::sendSynChar()
{
	//usartFsm->setState(usartFsm->getIdleState());
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
		if (ch == usartFsm->frame.syn)
		{
			//收到帧结束符，结束此帧的接收
			usartFsm->setState(usartFsm->getIdleState());
			return false;
		}
		else
		{
			//其余字符皆可能为命令指令，跳转入下一状态
			usartFsm->frame.dat.cmd = ch;
			usartFsm->setState(usartFsm->getWaitEtrState());
			return true;
		}
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