#include "WaitTailState.h"

WaitTailState::WaitTailState(Usart_FSM *pfsm) : usartFsm(pfsm)
{}

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

bool WaitTailState::sendSynChar()
{
	char ch;
	if(usartFsm->com.recv_data(&ch, 1) == 1)
	{

		//收到帧同步符，判断 valid 是否正确并跳转至相应状态
		if(ch == usartFsm->frame.syn)
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