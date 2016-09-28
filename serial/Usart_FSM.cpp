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

bool Usart_FSM::drive(Data &usrdat)
{
	while(!sendHead())
		;
#ifdef __DEBUG
	cout << "befor Usart_FSM::sendLength()\n";
#endif
	if(!sendLength())
		false;
#ifdef __DEBUG
	cout << "befor Usart_FSM::sendCmd()\n";
#endif
	if(!sendCmd())
		false;
#ifdef __DEBUG
	cout << "befor Usart_FSM::sendExtra()\n";
#endif
	if(!sendExtra())
		false;
#ifdef __DEBUG
	cout << "befor Usart_FSM::sendValid()\n";
#endif
	if(!sendValid())
		false;
#ifdef __DEBUG
	cout << "befor Usart_FSM::sendTail()\n";
#endif
	if(sendTail(usrdat))
		return true;
#ifdef __DEBUG
	cout << "Finish a whole dirve But Validation failed\n";
#endif
	
	return false;
}

bool Usart_FSM::sendHead()
{ return state->sendHead(); }
bool Usart_FSM::sendCmd()
{ return state->sendCmd(); }
bool Usart_FSM::sendValid()
{return  state->sendValid(); }
bool Usart_FSM::sendExtra()
{ return state->sendExtra(); }
bool Usart_FSM::sendLength()
{ return state->sendLength(); }

bool Usart_FSM::sendTail(Data &usrdat)
{
	if(state->sendTail())
	{
		usrdat = frame.dat;
		return true;
	}
	
	return false;
}



