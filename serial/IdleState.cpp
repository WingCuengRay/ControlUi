#include "IdleState.h"
using namespace std;

IdleState::IdleState(Usart_FSM* pfsm) : usartFsm(pfsm)
{}

bool IdleState::sendHead()
{
#ifdef __DEBUG
	cout << "IdleState::sendHead()\n";
#endif
	char ch;
	if(usartFsm->com.recv_data(&ch, 1) == 1)
	{
		#ifdef __DEBUG
			cout << "ch: " <<  hex << (int)ch << endl;
		#endif
		if(ch == usartFsm->frame.head)
		{
			usartFsm->setState(usartFsm->getWaitLenState());
			return true;
		}
		else
		{
			usartFsm->setState(usartFsm->getIdleState());
			return false;
		}
	}
	#ifdef __DEBUG
		cout << "end of IdleState::sendHead()" << endl;
	#endif
	
	return false;
}
bool IdleState::sendLength()
{
	return false;
}

bool IdleState::sendCmd()
{
	return false;
}

bool IdleState::sendExtra()
{
	return false;
}

bool IdleState::sendValid()
{
	return false;
}

bool IdleState::sendTail()
{
	return false;
}