#ifndef __USART_FSM_H
#define __USART_FSM_H

#include <memory>
#include "State.h"
#include "com.h"
#include "Frame.h"


class Usart_FSM
{
public:
	Usart_FSM(const Com& tmpcom);
	
	void setState(std::shared_ptr<State> tstate);

	bool sendHead();
	bool sendTail();
	bool sendCmd();
	bool sendValid();
	bool sendExtra();
	bool sendLength();
	
	std::shared_ptr<State> getIdleState();
	std::shared_ptr<State> getWaitLenState();
	std::shared_ptr<State> getWaitCmdState();
	std::shared_ptr<State> getWaitValidState();
	std::shared_ptr<State> getWaitEtrState();
	std::shared_ptr<State> getWaitTailState();

	Com com;
	Frame frame;
	
private:
	std::shared_ptr<State> state;
	std::shared_ptr<State> idleState;
	std::shared_ptr<State> waitLenState;
	std::shared_ptr<State> waitCmdState;
	std::shared_ptr<State> waitValidState;
	std::shared_ptr<State> waitEtrState;
	std::shared_ptr<State> waitTailState;
};

#endif