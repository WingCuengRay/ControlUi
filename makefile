VPATH = ./UI ./serial
CC := g++-6
CFLAGS:= -std=c++11 -Wall -O2
CFLAGS_DEBUG := -std=c++11 -Wall -g -D__DEBUG

CPP_SRC = $(wildcard ./*/*.cpp)
CPP_OBJS = $(patsubst %cpp, %o, $(CPP_SRC))

all: $(CPP_OBJS)
	$(CC) $(CFLAGS) -o main $^

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^


clear:
	rm -f ./UI/*.o ./serial/*.o
	

