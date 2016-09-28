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

//
// 有 BUG ，可能计算出来的验证字符恰好是 前同步符和尾同步符
//
bool WaitValidState::sendValid()
{
	char ch;
	if(usartFsm->com.recv_data(&ch, 1) == 1)
	{
		if (ch == usartFsm->frame.head)
		{
			//无论任何时候，一旦收到帧头，立刻重新开始新帧的读取
			usartFsm->setState(usartFsm->getWaitLenState());
			return false;
		}
		else if(ch == usartFsm->frame.tail)
		{
			//此时收到帧尾，代表校验字符缺失，丢弃此帧并回到空闲
			usartFsm->setState(usartFsm->getIdleState());
			return false;
		}
		else
		{
			usartFsm->frame.valid = ch;
			usartFsm->setState(usartFsm->getWaitTailState());
			return true;
		}
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

