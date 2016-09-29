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

//ע���¼�
//�ڶ�����������ʱ��Ҫʱָ��
#define REGISTEREVENT(eventID,eventBase) \
{ \
    EventManager *eventManager = EventManager::getSingleton(); \
    if(eventManager) \
        eventManager->registerEvent(eventID,eventBase); \
}

//�Ƴ���ע����¼�
#define UNREGISTREREVENT(eventID) \
{ \
    EventManager *eventManager = EventManager::getSingleton(); \
    if(eventManager) \
        eventManager->unRegisterEvent(eventID); \
}

#endif // EVENTMANAGER_H
