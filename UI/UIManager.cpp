#include "UIManager.h"
#include<cstddef>
#include"UIBase.h"
#include"ImfoManager.h"
#include"EventManager.h"
#include"DebugTool.h"
#include"UIMain.h"
#include"Module.h"
#include"UIRankFactory.h"
#include"DetailDefine.h"
#include"GlobalFunctionDeclaration.h"

UIManager::UIManager():
    SingleatonClass<UIManager>()
    ,pageType(PageType::PageMain)
{

}

UIManager::~UIManager()
{

}

void UIManager::initSingleton()
{
    initEvent();

    setMainPage();
    setPicturePage();
}
void UIManager::setMainPage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIManager::setMainPage\n");
    UIRankFactory *rankFactory = UIRankFactory::getSingleton();

    ImfoManager *imfoManager = ImfoManager::getSingleton();
    VecContentPageType pageContent = imfoManager->getPage(PageType::PageMain);

    UIMain *mainUI = new UIMain;
    mainUI->init(PageType::PageMain);
    UIRankAction* rankAction = rankFactory->create(RankType::RankBox);
    mainUI->setRankAndContent(rankAction,pageContent);
    uiPages.push_back(mainUI);



    EventManager *eventManager = EventManager::getSingleton();
    EventID sendEventID(EventType::EventTypeMain,EventDetail::DetailShowUI);
    VarList varList;
    eventManager->sendEvent(sendEventID,varList);
}
void UIManager::setPicturePage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIManager::setPicturePage\n");
    UIRankFactory *rankFactory = UIRankFactory::getSingleton();
    ImfoManager *imfoManager = ImfoManager::getSingleton();

    VecContentPageType pageContent = imfoManager->getPage(PageType::PagePicture);

    UIMain *pictureUI = new UIMain;
    pictureUI->init(PageType::PagePicture);
    UIRankAction* rankAction = rankFactory->create(RankType::RankBox);
    pictureUI->setRankAndContent(rankAction,pageContent);
    uiPages.push_back(pictureUI);

    EventManager *eventManager = EventManager::getSingleton();
    EventID sendEventID(EventType::EventTypePicture,EventDetail::DetailShowUI);
    VarList varList;
    eventManager->sendEvent(sendEventID,varList);
}
/*-------------------------------------
* EventBase virtual function
*-------------------------------------*/
void UIManager::processEvent(EventID eventID,VarList varList)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    EventManager *eventManager = EventManager::getSingleton();

    switch(eventID.type)
    {
        //接收到原始数据
    case EventType::EventTypeRecievePrimaryData:
        debugTool->outputString("UIManager::processEvent    process  receivePrimaryData\n");
        EventID newEventID;
        newEventID.type = pageTypeToEventType(pageType);
        newEventID.detail = intToEventDetail(varList.getNum());

        debugTool->outputString("\nUIManager::processEvent    leiyongcong output:    ");
        debugTool->outputString(EventIDToString(newEventID));
        debugTool->outputString("\n");

        eventManager->sendEvent(newEventID,varList);
        break;
    }
}
bool UIManager::initEvent()
{
    EventID eventID(EventType::EventTypeRecievePrimaryData,
                    EventDetail::DetailReceivedData);
    REGISTEREVENT(eventID,this);
    return true;
}
void UIManager::releaseEvent()
{

}
EventType UIManager::pageTypeToEventType(PageType type)
{
    switch(type)
    {
    case PageType::PageMain:
        return EventType::EventTypeMain;
    case PageType::PagePanel:
        return EventType::EventTypePanel;
    case PageType::PagePicture:
        return EventType::EventTypePicture;
    case PageType::PageSound:
        return EventType::EventTypeSound;
    default:
        return EventType::EventTypeInvalid;
    }
}
void UIManager::setPageType(PageType type)
{
    pageType = type;
}
EventDetail UIManager::intToEventDetail(int num)
{
    if(num < (int)EventDetail::DetailInvalid
       && num > (int)EventDetail::DetailMax)
        return EventDetail::DetailInvalid;
    EventDetail ret = (EventDetail)num;
    return ret;
}
