obj := SerialPort.cpp main.cpp Com.cpp table.cpp

all: $(obj)
	g++-6 -std=c++11 -o main $^

test: serial.cpp
	g++ -o serial $^
