#ifndef __USART_FSM_H
#define __USART_FSM_H

#include <memory>
#include "State.h"
#include "com.h"

class Usart_FSM
{
public:
	Usart_FSM(const com1& tmpcom) : com(tmpcom) 
	{
		idleState = make_shared<IdleState>(this);
		waitLenState = make_shared<WaitLenState>(this);
		waitCmdState = make_shared<WaitCmdState>(this);
		waitValidState = make_shared<WaitValidState>(this);
		waitEtrState = make_shared<WaitEtrState>(this);
		
		state = idleState;
	}
	
	void setState(shared_ptr<State> tstate)
	{
		state = tstate;
	}

	bool sendHead()
	{ state.sendHead(); }
	bool sendTail()
	{ state.sendTail(); }
	bool sendCmd()
	{ state.sendCmd(); }
	bool sendValid()
	{ state.sendValid(); }
	bool sendExtra()
	{ state.sendExtra(); }
	bool sendLength()
	{ state.sendLength(); }
	
	shared_ptr<State> getIdleState();
	shared_ptr<State> getWaitLenState();
	shared_ptr<State> getWaitCmdState();
	shared_ptr<State> getWaitValidState();
	shared_ptr<State> getWaitEtrState();
	shared_ptr<State> getWaitTailState();

	Com com;
	Frame frame;
	
private:
	shared_ptr<State> state;
	shared_ptr<State> idleState;
	shared_ptr<State> waitLenState;
	shared_ptr<State> waitCmdState;
	shared_ptr<State> waitValidState;
	shared_ptr<State> waitEtrState;
	shared_ptr<State> waitTailState;
};

#endif