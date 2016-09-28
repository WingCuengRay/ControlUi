obj := main.cpp SerialPort.cpp  Com.cpp table.cpp Frame.cpp Usart_FSM.cpp IdleState.cpp WaitLenState.cpp  WaitEtrState.cpp WaitCmdState.cpp WaitValidState.cpp WaitTailState.cpp 
obj_fsm := fsm_drive.cpp SerialPort.cpp  Com.cpp table.cpp Frame.cpp Usart_FSM.cpp IdleState.cpp WaitLenState.cpp  WaitEtrState.cpp WaitCmdState.cpp WaitValidState.cpp WaitTailState.cpp 

all: $(obj)
	clear
	g++-6 -std=c++11 -o main $^
	
fsm: $(obj_fsm)
	g++-6 -Wall -O2 -std=c++11 -o fsm $^
	
fsm_debug: $(obj_fsm)
	clear
	g++-6 -g -Wall -std=c++11 -D__DEBUG -o fsm $^


test: serial.cpp
	g++ -o serial $^
	
clean:
	rm -f *.o main fsm
