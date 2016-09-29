#ifndef __FRAME_H
#define __FRAME_H

#include <stdio.h>
#include <string.h>
#include "com.h"
#include <memory>
#include <vector>

typedef unsigned char uchar;
struct Data
{
	Data(uchar * s = NULL) : cmd(0)
	{
		//赋值给 etr
		if(s == NULL)
			return;
		for(int i=0; s[i]!=0; i++)
			etr.push_back(s[i]);
	}
	unsigned char cmd;
	std::vector<uchar> etr;
};

class Frame
{
public:
	Frame(unsigned char *s = NULL) : dat(s)
	{
		if(s == NULL)
			length = 1;
		else
			length = strlen((char *)s)+1;
	}
	
	
	bool Valid();
	
	static const uchar syn = 0x7e;
	unsigned char length;
	Data dat;
	unsigned char valid;
	
};


#endif