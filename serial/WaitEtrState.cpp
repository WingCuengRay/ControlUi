#include "WaitEtrState.h"

using namespace std;
WaitEtrState::WaitEtrState(Usart_FSM* pfsm) : usartFsm(pfsm)
{
	return;
}

bool WaitEtrState::sendSynChar()
{
	return false;	
}

bool WaitEtrState::sendLength()
{
	return false;
}

bool WaitEtrState::sendCmd()
{
	return false;
}

//
// 有 BUG ，可能额外数据段恰好包含 前同步符和尾同步符
//
bool WaitEtrState::sendExtra()
{
	char ch;
	vector<uchar> tmp;
	
	//接收额外数据，由 length 字段确定其长度
	for(size_t i=usartFsm->frame.length-1; i!=0; )
	{
		// 数据字段的字符若出现 前同步符 与 尾同步符，则不去理会
		// 后期可以处理额外数据中的 同步符
		if(usartFsm->com.recv_data(&ch, 1) == 1)
		{
			tmp.push_back(ch);
			i--;
		}
		// 可能会引起接收一帧的超时，导致失败
		else
		{
			usartFsm->setState(usartFsm->getIdleState());
			return false;
		}
	}
	
	usartFsm->frame.dat.etr = tmp;
	usartFsm->setState(usartFsm->getWaitValidState());
	return true;
}

bool WaitEtrState::sendValid()
{
	return false;
}

