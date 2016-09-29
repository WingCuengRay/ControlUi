#include "IdleState.h"
using namespace std;

IdleState::IdleState(Usart_FSM* pfsm) : usartFsm(pfsm)
{}

bool IdleState::sendSynChar()
{
#ifdef __DEBUG
	cout << "IdleState::sendSynChar()\n";
#endif
	unsigned char ch;
	if(usartFsm->com.recv_OneByte(&ch) == 1)
	{
	#ifdef __DEBUG
		cout << "ch: " <<  hex << (unsigned int)ch << endl;
	#endif
	
		if(ch == usartFsm->frame.syn)
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