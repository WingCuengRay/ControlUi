#include <stdio.h>
#include <string.h>

struct Frame
{
public:
	Frame(unsigned char *s = NULL) : etr(s)
	{
		if(s == NULL)
			length = 1;
		else
			length = strlen(s)+1;
	}
	unsigned char head = 0x55;
	unsigned char length;
	unsigned char cmd;
	unsigned char *etr;
	unsigned char tail = 0x56;
};