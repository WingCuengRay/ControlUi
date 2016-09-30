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
#include"UIContentFactory.h"

UIManager::UIManager():
    SingleatonClass<UIManager>()
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
    setPanelPage();
    setSoundPage();

    EventManager* eventManger = EventManager::getSingleton();
    EventID eventID(EventType::EventTypeMain,EventDetail::DetailShowUI);
    VarList varList;
    eventManger->sendEvent(eventID,varList);
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

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();
    UIRankAction* rankAction = rankFactory->create(RankType::RankBox);
    UIContentBase* contentSign = contentFactory->create(ContentType::ContentString);
    string stringSign("*");
    contentSign->setValue(&stringSign);

    mainUI->setRankAndContent(rankAction,contentSign,pageContent);
    uiPages.push_back(mainUI);
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

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();
    UIRankAction* rankAction = rankFactory->create(RankType::RankBox);
    UIContentBase* contentSign = contentFactory->create(ContentType::ContentString);
    string stringSign("*");
    contentSign->setValue(&stringSign);

    pictureUI->setRankAndContent(rankAction,contentSign,pageContent);
    uiPages.push_back(pictureUI);
}
void UIManager::setPanelPage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIManager::setPanelPage\n");
    UIRankFactory *rankFactory = UIRankFactory::getSingleton();
    ImfoManager *imfoManager = ImfoManager::getSingleton();

    VecContentPageType pageContent = imfoManager->getPage(PageType::PagePanel);

    UIMain *panelUI = new UIMain;
    panelUI->init(PageType::PagePanel);

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();
    UIRankAction* rankAction = rankFactory->create(RankType::RankBox);
    UIContentBase* contentSign = contentFactory->create(ContentType::ContentString);
    string stringSign("*");
    contentSign->setValue(&stringSign);

    panelUI->setRankAndContent(rankAction,contentSign,pageContent);
    uiPages.push_back(panelUI);
}
void UIManager::setSoundPage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIManager::setPicturePage\n");
    UIRankFactory *rankFactory = UIRankFactory::getSingleton();
    ImfoManager *imfoManager = ImfoManager::getSingleton();

    VecContentPageType pageContent = imfoManager->getPage(PageType::PageSound);

    UIMain *souneUI = new UIMain;
    souneUI->init(PageType::PageSound);

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();
    UIRankAction* rankAction = rankFactory->create(RankType::RankBox);
    UIContentBase* contentSign = contentFactory->create(ContentType::ContentString);
    string stringSign("*");
    contentSign->setValue(&stringSign);

    souneUI->setRankAndContent(rankAction,contentSign,pageContent);
    uiPages.push_back(souneUI);

}

EventDetail UIManager::coutEventDetail(int cmd)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    ChangeValueType type = intToChangeValueType(cmd);
    switch(type)
    {
    case ChangeValueType::ChangeValueTypeBigger:
    case ChangeValueType::ChangeValueTypeSmaller:
        //debugTool->newOutput("EventDetail::DetailChangeValue");
        return EventDetail::DetailChangeValue;
    case ChangeValueTypeTurnUp:
        debugTool->newOutput("EventDetail::DetailTurnUp");
        return EventDetail::DetailTurnUp;
    case ChangeValueTypeTurnDown:
        debugTool->newOutput("EventDetail::DetailTurnDown");
        return EventDetail::DetailTurnDown;
    default:
        {
            DebugTool *debugTool = DebugTool::getSingleton();
            debugTool->outputString("UIManager::coutEventDetail unknow unknow unknow cmd\n");
            return EventDetail::DetailInvalid;
        }
    }
}
/*-------------------------------------
* EventBase virtual function
*-------------------------------------*/
void UIManager::processEvent(EventID eventID,VarList varList)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    EventManager *eventManager = EventManager::getSingleton();
    //debugTool->newOutput("UIManager::processEvent    process  receivePrimaryData\n");
    switch(eventID.type)
    {
        //接收到原始数据
    case EventType::EventTypeRecievePrimaryData:

        EventID newEventID;

        newEventID.type = pageTypeToEventType(currentUI->getPageType());
        newEventID.detail = coutEventDetail(varList.getNum());

        varList.setSign(intToChangeValueType(varList.getNum()));
        varList.setNum(currentUI->getIndex());

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

EventDetail UIManager::intToEventDetail(int num)
{
    if(num < (int)EventDetail::DetailInvalid
       || num > (int)EventDetail::DetailMax)
        return EventDetail::DetailInvalid;
    EventDetail ret = (EventDetail)num;
    return ret;
}
void UIManager::setCurrentUI(UIBase* para)
{
    currentUI = para;

}
