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
		if(ch == usartFsm->frame.head)
		{
			//一旦收到帧头，立刻重新开始新帧的读取
			usartFsm->setState(usartFsm->getWaitLenState());
			return false;
		}
		//收到帧尾，判断 valid 是否正确并跳转至相应状态
		else if(ch == usartFsm->frame.tail)
		{			
			if(usartFsm->frame.Valid()==true)
			{
				//校验正确，完成接收一帧
				usartFsm->setState(usartFsm->getIdleState());
				return true;
			}
			//不正确，则重新回空闲状态准备接收
			else						
			{	
				usartFsm->setState(usartFsm->getIdleState());
				return false;
			}
		}
		//垃圾字符（不是位同步符）则简单丢弃，并回到空闲状态
		else
		{
			usartFsm->setState(usartFsm->getIdleState());
			return false;
		}
	}

	usartFsm->setState(usartFsm->getIdleState());
	return false;
}