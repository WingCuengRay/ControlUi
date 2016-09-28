#include "Usart_FSM.h"

using namespace std;

shared_ptr<State> Usart_FSM::getIdleState()
{
	return idleState;
}

shared_ptr<State> Usart_FSM::getWaitLenState()
{
	return waitLenState;
}

shared_ptr<State> Usart_FSM::getWaitCmdState()
{
	return waitCmdState;
}

shared_ptr<State> Usart_FSM::getWaitValidState()
{
	return waitValidState;
}

shared_ptr<State> Usart_FSM::getWaitEtrState()
{
	return waitEtrState;
}

shared_ptr<State> Usart_FSM::getWaitTailState()
{
	return waitTailState;
}


bool Usart_FSM::sendHead()
{ 
	state.sendHead(); 
}