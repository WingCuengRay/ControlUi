CC := g++-6
CFLAGS := -std=c++11 -Wall -O2
CFLAGS_DEBUG := -std=c++11 -Wall -g -D__DEBUG


objs:= DebugTool.o EventAddMinus.o EventBase.o EventManager.o \
		EventUIMain.o GlobalFunction.o ImfoManager.o main.o MessageManager.o \
		Module.o SingletonClass.o SystermManager.o UIBase.o UIContentBase.o  \
		UIContentFactory.o UIContentItem.o UIMain.o UIManager.o UIPanel.o \
		UIRankAction.o UIRankActionBox.o UIRankFactory.o UITool.o \
		
all: $(objs)
	clear
	g++-6 $(CFLAGS) -o main $^
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^
	
clean:
	rm -f *.o main fsm
