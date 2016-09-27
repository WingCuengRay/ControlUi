#ifndef __PORT_H
#define __PORT_H

#include <string>
#include <iostream>

extern "C"
{
	#include <fcntl.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <termios.h>//÷’∂Àøÿ÷∆∂®“Â  
	#include <errno.h>  
	#include <stdio.h>  
};

enum DataBits{
	SEVEN=7,EIGHT=8
};
enum StopBits{
	ZERO=0, ONE=1, TWO=2
};
enum Parity
{
	N='N', E='E', O='O', S='S', n='n', e='e', o='o', s='s'
};


class Port
{
public:
	Port(int speed = 9600, bool fc = 0, DataBits db = EIGHT, StopBits sb = ONE,
		Parity pa = N)
	{
		setPortAttr(speed, fc, db, sb, pa);
	}
	
	void setPortAttr(int speed, bool fc, DataBits db, StopBits sb,
		Parity pa)
	{
		baud = speed;
		flow_ctrl = fc;
		databits = db;
		stopbits = sb;
		parity = pa;
	}
	
	bool bindCom(int fd);
	
private:	
	int baud;
	bool flow_ctrl;
	DataBits databits;
	StopBits stopbits;
	Parity parity;
};

#endif