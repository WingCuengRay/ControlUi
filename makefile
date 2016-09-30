VPATH = ./UI ./serial
CC := g++-6
CFLAGS:= -std=c++11 -Wall -O2 -lncurses
CFLAGS_DEBUG := -std=c++11 -Wall -g -D__DEBUG_MAIN -lncurses

CPP_SRC = $(wildcard ./*/*.cpp)
CPP_OBJS = $(patsubst %cpp, %o, $(CPP_SRC))


main1: $(CPP_OBJS)
	$(CC) $(CFLAGS_DEBUG) -o $@ $^

%.o:%.cpp
	$(CC) $(CFLAGS_DEBUG) -c -o $@ $^


clean:
	rm -f ./UI/*.o ./serial/*.o
	

