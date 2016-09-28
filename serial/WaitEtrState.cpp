#include "WaitEtrState.h"

using namespace std;
WaitEtrState::WaitEtrState(Usart_FSM* pfsm) : usartFsm(pfsm)
{
	return;
}

bool WaitEtrState::sendHead()
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

bool WaitEtrState::sendExtra()
{
	char ch;
	vector<uchar> tmp;
	
	for(size_t i=usartFsm->frame.length-1; i!=0; )
	{
		if(usartFsm->com.recv_data(&ch, 1) == 1)
		{
			tmp.push_back(ch);
			i--;
		}
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

bool WaitEtrState::sendTail()
{
	return false;
}