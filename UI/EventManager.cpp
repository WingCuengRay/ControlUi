
#include"EventManager.h"
#include"GlobalFunctionDeclaration.h"
#include<string>
#include"DetailDefine.h"
#include"DebugTool.h"

EventManager::EventManager():SingleatonClass<EventManager>()
{

}
EventManager::~EventManager()
{

}

void EventManager::initSingleton()
{

}
void EventManager::registerEvent(EventID &newEventID,EventBase* newEvent)
{
    if(mapEvent.find(newEventID) == mapEvent.end())
    {

        mapEvent[newEventID] = newEvent;
#ifdef PLATFORM_WIN32
    globalWriteFile(WriteDirection::DirecttionEvent,newEventID);
#endif // PLATFORM_WIN32
        return ;
    }
#ifdef PLATFORM_WIN32
    globalWriteFile(WriteDirection::DirectionError,newEventID);
#endif // PLATFORM_WIN32
    return ;
}
void EventManager::unRegisterEvent(const EventID&)
{

}

void EventManager::sendEvent(EventID eventID,VarList varList)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("EventManager::sendEvent\n");

    if(mapEvent.find(eventID) != mapEvent.end())
    {
        debugTool->outputString("find event processor success\n");
        EventBase* temp = mapEvent[eventID];
        temp->processEvent(eventID,varList);
    }
    else
    {
        globalWriteFile(WriteDirection::DirectionError,eventID);
        debugTool->outputString("can't find event processor");
    }
}
