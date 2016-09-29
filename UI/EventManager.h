#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H


#include"DetailDefine.h"
#include"EventBase.h"
#include"SingletonClass.h"

#include<map>


class EventManager:public SingleatonClass<EventManager>
{
public:
    EventManager();
    virtual ~EventManager();
    void registerEvent(EventID&,EventBase*);
    void unRegisterEvent(const EventID &);
    void sendEvent(EventID eventID,VarList varList);
    virtual void initSingleton();
private:
    std::map<EventID,EventBase*> mapEvent;
};

//注册事件
//第二个参数传入时需要时指针
#define REGISTEREVENT(eventID,eventBase) \
{ \
    EventManager *eventManager = EventManager::getSingleton(); \
    if(eventManager) \
        eventManager->registerEvent(eventID,eventBase); \
}

//移除已注册的事件
#define UNREGISTREREVENT(eventID) \
{ \
    EventManager *eventManager = EventManager::getSingleton(); \
    if(eventManager) \
        eventManager->unRegisterEvent(eventID); \
}

#endif // EVENTMANAGER_H
