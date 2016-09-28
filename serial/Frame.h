#include <stdio.h>
#include <string.h>
#include "com.h"

typedef unsigned char uchar;
struct Data
{
	unsigned char cmd;
	string etr;
};

class Frame
{
public:
	Frame(unsigned char *s = NULL) : etr(s)
	{
		if(s == NULL)
			length = 1;
		else
			length = strlen(s)+1;
	}
	
	
	bool Valid();
	
	const unsigned char head = 0x55;
	unsigned char length;
	Data dat;
	unsigned char valid;
	const unsigned char tail = 0x56;
	
	/**
	bool fsm_getData(const Com& com)
	{
		uchar ch;
		//空闲等待
		while(1)
		{
			if(recv_data(&ch, 1)==1)
			{
				if(ch == head)
					break;
			}
			else		//接收失败（或非阻塞模式无数据接收）
				return false;
		}
		
		if(recv_data(&ch, 1)==1)
		{
			length = ch;
		}
		if(recv_data(&ch, 1)==1)
		{
			dat.cmd = ch;
		}
		
		string tmp;
		for(int i=length; i!=0; i--)
		{
			if(recv_data(&ch, 1) != 1)
				return false;
			tmp.push_back(ch);
		}
		
		if(recv_data(&ch, 1)==1)
		{
			if(ch == )
		}
		
	}
	**/
};