#include "MessageManager.h"
#include"DetailDefine.h"
#include"DebugTool.h"
#include"EventManager.h"
#include"GlobalFunctionDeclaration.h"
#include"DebugTool.h"

MessageManager::MessageManager():SingleatonClass<MessageManager>()
{

}

MessageManager::~MessageManager()
{

}

void MessageManager::sendMessage(Data data)
{
	//bug!!!  DetailMax 为 enum 无制定值
	//DetailMax = 8, DetailInvaild = 0
    if(data.cmd > (int)EventDetail::DetailInvalid
       && data.cmd < (int)EventDetail::DetailMax)
    {
        vecMessage.push_back(data);
    }
    else
    {
        DebugTool *debugTool = DebugTool::getSingleton();
		//debugTool->outputString("MessageManager::sendMessage message datat invalid\n");
        debugTool->outputString(string("MessageManager::sendMessage message datat invalid\n") + string("Max: ") + std::to_string((int)EventDetail::DetailMax));
    }
}
void MessageManager::update(float deltaTime)
{
    static int timeCount = 0;
    static const int timeWait = 0;			//bug! deltaTime 是 float，这里是 int!?
    timeCount += deltaTime;

	
    if(timeCount < timeWait)
        return ;
    timeCount -= timeWait;

    vector<Data>::iterator ite = vecMessage.begin();
    bool isSolveOne = false;//1次最多解决一个问题

    while(ite != vecMessage.end())
    {
        Data data = *ite;
        if(data.cmd > (int)EventDetail::DetailInvalid
           && data.cmd < (int)EventDetail::DetailMax )
        {
            isSolveOne = true;
            EventID eventID(EventType::EventTypeRecievePrimaryData,
                            EventDetail::DetailReceivedData);
            VarList varList;
            varList.setNum(data.cmd);
            EventManager *eventManager = EventManager::getSingleton();
            eventManager->sendEvent(eventID,varList);
        }
        if(isSolveOne == true)
            break;
        ite++;
    }
}
void MessageManager::initSingleton()
{

}
