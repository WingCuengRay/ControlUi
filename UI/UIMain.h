#ifndef UIMAIN_H
#define UIMAIN_H

#include<string>
#include<vector>
#include<map>
using std::vector;
using std::map;
using std::string;

#include"UIBase.h"
#include"EventBase.h"
#include"DetailDefine.h"
#include"UIContentBase.h"


class UIMain:public UIBase,public EventBase
{

    typedef vector<UIContentBase*> VecContentItemType;
    typedef vector<VecContentItemType> VecContentPageType;
public:
    UIMain();
    virtual ~UIMain();
    bool init(PageType pageTypePara);
public://virtual

    //UIBase
    virtual void show();
    virtual bool initUI(PageType pageTypePara);

    //EventBase 有时间用命令模式
    virtual void processEvent(EventID,VarList);
    virtual void processEventMain(EventID,VarList);
    virtual void processEventPicture(EventID,VarList);
    virtual void processEventSound(EventID,VarList);
    virtual void processEventPanel(EventID,VarList);
    virtual bool initEvent();
    virtual void releaseEvent();
private:

    void changeValue(EventID,VarList);
    void turnUpDown(EventID,VarList);

private:
    //todo detail content

    EventType pageEventType;
    int itemNum;

};

#endif // UIMAIN_H
