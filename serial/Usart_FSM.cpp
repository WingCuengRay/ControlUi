#include "Usart_FSM.h"
#include "IdleState.h"
#include "WaitEtrState.h"
#include "WaitLenState.h"
#include "WaitCmdState.h"
#include "WaitValidState.h"
#include "WaitTailState.h"

using namespace std;

Usart_FSM::Usart_FSM(const Com& tmpcom) : com(tmpcom) 
{
	idleState = std::make_shared<IdleState>(this);
	waitLenState = std::make_shared<WaitLenState>(this);
	waitCmdState = std::make_shared<WaitCmdState>(this);
	waitValidState = std::make_shared<WaitValidState>(this);
	waitEtrState = std::make_shared<WaitEtrState>(this);
	waitTailState = std::make_shared<WaitTailState>(this);

	/**
	idleState = shared_ptr<State>(static_cast<State *>(new IdleState(this)));
	waitLenState = shared_ptr<State>(static_cast<State *>(new WaitLenState(this)));
	waitCmdState = shared_ptr<State>(static_cast<State *>(new WaitCmdState(this)));
	waitValidState = shared_ptr<State>(static_cast<State *>(new WaitValidState(this)));
	waitEtrState = shared_ptr<State>(static_cast<State *>(new WaitEtrState(this)));
	waitTailState = shared_ptr<State>(static_cast<State *>(new WaitTailState(this)));
	**/
	
	state = idleState;
}

void Usart_FSM::setState(std::shared_ptr<State> tstate)
{
	state = tstate;
}

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
{ return state->sendHead(); }
bool Usart_FSM::sendTail()
{ return state->sendTail(); }
bool Usart_FSM::sendCmd()
{ return state->sendCmd(); }
bool Usart_FSM::sendValid()
{return  state->sendValid(); }
bool Usart_FSM::sendExtra()
{ return state->sendExtra(); }
bool Usart_FSM::sendLength()
{ return state->sendLength(); }

