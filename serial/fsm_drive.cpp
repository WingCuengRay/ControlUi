#include "Usart_FSM.h"

using namespace std;
int main(void)
{
	SerialPort port1(9600);
	Com com1("/dev/ttyS0", make_shared<SerialPort>(port1));
	
	if(com1.OpenCom() == false)
	{
		cout << "OpenCom error." << endl;
		cout << com1.name << endl;
		return 0;
	}
	if(!com1.bind())
	{
		cout << "Bind USART error." << endl;
		return 0;
	}
	
	char s[512];
	int ret = com1.recv_data(s, 512);
	s[ret] = 0;
	for(int i=0; i<ret; i++)
		cout << hex << (int)s[i] << ' ';
	cout << endl;
	
	Usart_FSM *pfsm = new Usart_FSM(com1);
	#ifdef __DEBUG
		cout << "FSM starting.\n";
	#endif
	
	if(pfsm->sendHead())
		cout << "sendHead success!\n";
	if(pfsm->sendLength())
		cout << "sendLength success!\n";
	if(pfsm->sendCmd())
		cout << "sendCmd success!\n";
	if(pfsm->sendExtra())
		cout << "sendExtra success!\n";
	if(pfsm->sendValid())
		cout << "sendValid success!\n";
	if(pfsm->sendTail())
		cout << "sendTail success && Validation OK!\n";
		
	return 0;
}