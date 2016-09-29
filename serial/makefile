CC := g++-6
CFLAGS := -std=c++11 -Wall -O2
CFLAGS_DEBUG := -std=c++11 -Wall -g -D__DEBUG

obj := main.o SerialPort.o  com.o table.o Frame.o Usart_FSM.o IdleState.o WaitLenState.o  \
		WaitEtrState.o WaitCmdState.o WaitValidState.o WaitTailState.o 
obj_fsm := fsm_drive.o SerialPort.o  com.o table.o Frame.o Usart_FSM.o IdleState.o WaitLenState.o  \
		WaitEtrState.o WaitCmdState.o WaitValidState.o WaitTailState.o 

fsm: $(obj_fsm)
	clear
	$(CC) $(CFLAGS_DEBUG) -o $@ $^
	
fsm_debug: $(obj_fsm)
	clear
	$(CC) $(CFLAGS_DEBUG) -o $@ $^
	
%.o: %.cpp
	$(CC) $(CFLAGS_DEBUG) -c -o $@ $^
	
clean:
	rm -f *.o main fsm
