VPATH = ./UI ./serial
CC := g++-6
CFLAGS:= -std=c++11 -Wall -O2 
CFLAGS_DEBUG := -std=c++11 -Wall -g -D__DEBUG

CPP_SRC = $(wildcard ./*/*.cpp)
CPP_OBJS = $(patsubst %cpp, %o, $(CPP_SRC))

all: $(CPP_OBJS)
	$(CC) $(CFLAGS_DEBUG) -o main $^

%.o:%.cpp
	$(CC) $(CFLAGS_DEBUG) -c -o $@ $^


clean:
	rm -f ./UI/*.o ./serial/*.o
	

