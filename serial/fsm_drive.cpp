#include "Usart_FSM.h"
#include "Frame.h"

#include "../UI/MessageManager.h"
#include "../UI/EventManager.h"
#include "../UI/DetailDefine.h"
#include "../UI/UIManager.h"
#include "../UI/GlobalFunctionDeclaration.h"

using namespace std;

int cntCorrectTime(Usart_FSM *pfsm)
{
	Data usrdat;
	int i = 0;
	while(1)
	{
		//保证每次循环开始处于起始状态
		if(pfsm->drive(usrdat))
		{
			i++;
			if(i%100 == 0)
				cout << "Recieve successfully. Times: " << i << '\n';
		}
	}
	
	return i;
}



int main(void)
{
	SerialPort port1(115200);
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

#ifdef __DEBUG
	char s[512];
	int ret = com1.recv_data(s, 512);
	s[ret] = 0;
	for(int i=0; i<ret; i++)
		cout << hex << (unsigned int)s[i] << ' ';
	cout << endl;
#endif

	Usart_FSM *pfsm = new Usart_FSM(com1);
	// 串口丢包率测试函数
	// cntCorrectTime(pfsm);
#ifdef __DEBUG
	cout << "FSM starting.\n";
#endif

	
	Data usrdat;
	while(1)
	{
		if(pfsm->drive(usrdat))
		{
		#ifdef __DEBUG
			cout << "cmd:\t" << hex << (int)usrdat.cmd << endl;
			cout << "extra:\t";
			for(auto it=usrdat.etr.cbegin(); it!=usrdat.etr.cend(); it++)
				cout << hex << (int)(*it) << ' ';
			cout << endl;
		#endif
		
		//不需要初始化，注册事件？
		//MessageManager *messageManager = MessageManager::getSingleton();
		//messageManager->sendMessage(usrdat);
		//messageManager->update();
		//cout << "Running MessageManager.\n" << endl;
		}
	}
		
	return 0;
}
