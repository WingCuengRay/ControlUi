VPATH = ./UI ./serial
CC := g++-6
CFLAGS:= -std=c++11 -Wall -O2 
CFLAGS_DEBUG := -std=c++11 -Wall -g -D__DEBUG

CPP_SRC = $(wildcard ./*/*.cpp)
CPP_OBJS = $(patsubst %cpp, %o, $(CPP_SRC))


%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^


clean:
	rm -f ./UI/*.o ./serial/*.o
	

