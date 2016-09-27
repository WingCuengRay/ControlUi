obj := SerialPort.cpp main.cpp Com.cpp

all: $(obj)
	g++ -std=c++0x -o main $^

test: serial.cpp
	g++ -o serial $^
