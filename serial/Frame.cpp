#include "Frame.h"

using namespace std;
bool Frame::Valid()
{
	uchar res = head ^ tail ^ length ^ dat.cmd;
	for(unsigned int i=0; i<dat.etr.size(); i++)
		res ^= dat.etr[i];
	
#ifdef __DEBUG
	cout << "In Frame::Valid() :\n";
	cout << "\tValidation Code: 0x" << hex << (int)valid << endl;
	cout << "\That should be: 0x" << hex << (int)res << endl;
#endif
	
	if(res == valid)
		return true;
	else
		return false;
}