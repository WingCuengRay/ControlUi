#ifndef UIMANAGER_H
#define UIMANAGER_H

#include<vector>
using std::vector;

#include"SingletonClass.h"
#include"EventBase.h"
class UIBase;

class UIManager:public SingleatonClass<UIManager>,public EventBase
{
public:
    UIManager();
    virtual ~UIManager();
public://virtual

    //EventBase
    virtual void processEvent(EventID,VarList);
    virtual bool initEvent();
    virtual void releaseEvent();

    virtual void initSingleton();
    void setMainPage();
    void setPicturePage();
    void setSoundPage();
    void setPanelPage();
    void setCurrentUI(UIBase*);
private:
    EventType pageTypeToEventType(PageType type);
    EventDetail intToEventDetail(int );
    EventDetail coutEventDetail(int);
private:
    vector<UIBase *> uiPages;
    UIBase* currentUI;
};

#endif // UIMANAGER_H
