#include "Usart_FSM.h"
#include "Frame.h"

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
	
	Data usrdat;
	while(1)
	{
		//保证每次循环开始处于起始状态
		pfsm->setState(pfsm->getIdleState());
		if(pfsm->drive(usrdat))
		{
			cout << "cmd:\t" << hex << (int)usrdat.cmd << endl;
			cout << "extra:\t";
			for(auto it=usrdat.etr.cbegin(); it!=usrdat.etr.cend(); it++)
				cout << hex << (int)(*it) << ' ';
			cout << endl;
		}
	}
		
	return 0;
}