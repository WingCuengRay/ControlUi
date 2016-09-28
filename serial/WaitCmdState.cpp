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
		if (ch == usartFsm->frame.head)
		{
			//一旦收到帧头，立刻重新开始新帧的读取
			usartFsm->setState(usartFsm->getWaitLenState());
			return false;
		}
		else if(ch == usartFsm->frame.tail)
		{
			//此时收到帧尾，代表中间按字符有丢失，丢弃此帧并重新等待
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

bool WaitCmdState::sendTail()
{
	return false;
}
