#include "WaitValidState.h"


WaitValidState::WaitValidState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

bool WaitValidState::sendSynChar()
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
	if(usartFsm->com.recv_OneByte(&ch) == 1)
	{
		if (ch == usartFsm->frame.syn)
		{
			//此时收到帧尾，代表校验字符缺失，丢弃此帧并回到空闲
			usartFsm->setState(usartFsm->getIdleState());
			return false;
		}
		else
		{
			//转义字符，用于使转义 '\' 后的字符失去含义(同步符)
			if(ch == '\\' )			//0x5c
			{
				// 转义字符后的字符接收失败
				if(usartFsm->com.recv_OneByte(&ch) != 1)
					return false;
			}
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

