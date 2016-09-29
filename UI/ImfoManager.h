#ifndef IMFOMANAGER_H
#define IMFOMANAGER_H

#include<vector>
#include<map>
using std::vector;
using std::map;

#include"DetailDefine.h"

#include"SingletonClass.h"
class UIContentBase;
class EventBase;

typedef vector<UIContentBase*> VecContentItemType;
typedef vector<VecContentItemType> VecContentPageType;
typedef map<PageType,VecContentPageType> MapPageTypeContent;

typedef vector<EventID> VecEventID;
typedef map<PageType,VecEventID> MapPageEventID;


class ImfoManager:public SingleatonClass<ImfoManager>
{
public:
    ImfoManager();
    virtual ~ImfoManager();

    VecContentPageType getPage(PageType);
    VecEventID getPageEventID(PageType);
    virtual void initSingleton();
private:
    void setMainPage();
    void setMainPageEventID();
    void setPicturePage();
    void setPictureEventID();
    void setPanelPage();
    void setPanelPageEventID();
private:
    MapPageTypeContent mapPageContents;
    MapPageEventID pageEventID;
};

#endif // IMFOMANAGER_H
