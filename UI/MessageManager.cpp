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
    if(data.cmd < (int)EventDetail::DetailMax
       && data.cmd > (int)EventDetail::DetailInvalid)
    {
        vecMessage.push_back(data);
    }
    else
    {
        DebugTool *debugTool = DebugTool::getSingleton();
        debugTool->outputString("MessageManager::sendMessage message datat invalid\n");
    }
}
void MessageManager::update(float deltaTime)
{
//    static float timeCount = 0;
//    static const float timeWait = 1;
//    timeCount += deltaTime;
//
//    if(timeCount < timeWait)
//        return ;
//    timeCount -= timeWait;

    vector<Data>::iterator ite = vecMessage.begin();
    bool isSolveOne = false;//1次最多解决一个问题

    while(ite != vecMessage.end())
    {
        Data data = *ite;
        if(data.cmd < (int)EventDetail::DetailMax
           && data.cmd > (int)EventDetail::DetailInvalid)
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
