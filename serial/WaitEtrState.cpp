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
	unsigned char ch;
	vector<uchar> tmp;
	
	//接收额外数据，由 length 字段确定其长度
	for(size_t i=usartFsm->frame.length-1; i!=0; )
	{
		// 处理额外数据中的 同步符，同步符所代表的数据为 0x5C+同步符
		if(usartFsm->com.recv_OneByte(&ch)==1 && ch!=0x7E)
		{
			// 接收转义字符及其后面的字符
			if(ch == '\\')
			{
				if(usartFsm->com.recv_OneByte(&ch) != 1)
					return false;
			}
				
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

