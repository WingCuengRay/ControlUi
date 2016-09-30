#include "UIMain.h"
#include "EventManager.h"
#include"ImfoManager.h"
#include"DebugTool.h"
#include"UIRankAction.h"
#include"UITool.h"
#include"UIManager.h"
#include <curses.h>

UIMain::UIMain()
{

}


UIMain::~UIMain()
{

}

bool UIMain::init(PageType pageTypePara)
{
    //顺序不可调
    initUI(pageTypePara);
    initEvent();
    return true;

}



void UIMain::show()
{
    DebugTool *debugTool = DebugTool::getSingleton();
//    debugTool->outputString("UIMain::show\n");
    UITool *uiTool = UITool::getSingleton();
	uiTool->clearWindow();
	uiTool->refresh();
    

    rankAction->show();
	uiTool->refresh();
    SizeBox sizeBox;
    sizeBox.topLeftX = signX;
    sizeBox.topLeftY = signY;
    signContent->show(sizeBox);
	uiTool->refresh();


    UIManager *uiManager = UIManager::getSingleton();
    uiManager->setCurrentUI(this);

    //uiTool->refresh();
}

bool UIMain::initUI(PageType pageTypePara)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIMain::initUI\n");

    pageType = pageTypePara;
    pageEventType = pageTypeToEventType(pageType);
    return true;
}
/*--------------------------------------
* EventBase vritual function
*--------------------------------------*/
void UIMain::processEvent(EventID eventID,VarList varList)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIMain processEvent\n");
    if(eventID.type != pageEventType)
        return ;

    switch(eventID.type)
    {
    case EventType::EventTypeInvalid:
        break;
    default:
        processEventMain(eventID,varList);
        break;
    }
}
void UIMain::processEventMain(EventID eventID,VarList varList)
{
    if(eventID.type != pageEventType)
        return ;
    switch(eventID.detail)
    {
    case EventDetail::DetailShowUI:
        show();
        break;
    case EventDetail::DetailChangeValue:
        changeValue(eventID,varList);
        break;
    case EventDetail::DetailTurnUp:
    case EventDetail::DetailTurnDown:
        turnUpDown(eventID,varList);
        break;
    }
}
void UIMain::processEventPicture(EventID eventID,VarList varList)
{
    if(eventID.type != pageEventType)
        return ;
    switch(eventID.detail)
    {
    case EventDetail::DetailShowUI:
        show();
        break;
    case EventDetail::DetailChangeValue:
        changeValue(eventID,varList);
        break;
    case EventDetail::DetailGoAhead:
        break;
    }
}
void UIMain::processEventSound(EventID eventID,VarList varList)
{
    if(eventID.type != pageEventType)
        return ;
    switch(eventID.detail)
    {
    case EventDetail::DetailShowUI:
        show();
        break;
    case EventDetail::DetailChangeValue:
        changeValue(eventID,varList);
        break;
    case EventDetail::DetailGoAhead:
        break;
    }
}
void UIMain::processEventPanel(EventID eventID,VarList varList)
{
    if(eventID.type != pageEventType)
        return ;
    switch(eventID.detail)
    {
    case EventDetail::DetailShowUI:
        show();
        break;
    case EventDetail::DetailChangeValue:
        changeValue(eventID,varList);
        break;
    case EventDetail::DetailGoAhead:
        break;
    }
}
bool UIMain::initEvent()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIMain::initEvent\n");

    ImfoManager *imfoManager = ImfoManager::getSingleton();
    VecEventID vecEventID = imfoManager->getPageEventID(pageType);
    VecEventID::iterator ite = vecEventID.begin();
    while(ite != vecEventID.end())
    {
        EventID temp = *ite;
        REGISTEREVENT(temp,this);
        ++ite;
    }
    return true;
}
void UIMain::releaseEvent()
{

}
void UIMain::turnUpDown(EventID eventID,VarList varList)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIMain::turnUpDown    ");
    switch(eventID.detail)
    {
    case EventDetail::DetailTurnUp:
        if(index < pageContent.size() - 1)
        {
            index++;
            signY = rankAction->getLineY(index);
        }
        show();
        break;
    case EventDetail::DetailTurnDown:
        if(index > 2)
        {
            index--;
            signY = rankAction->getLineY(index);
        }
        show();
        break;
    }
}
void UIMain::changeValue(EventID eventID,VarList varList)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIMain::changeValue    ");

    int num = varList.getNum();
    int sign = varList.getSign();
    if(num < pageContent.size())
    {
        VecContentItemType item = pageContent[num];
        VecContentItemType::iterator iteContent = item.begin();
        //对一条项中的所有内容进行修改，假如不能修改，由内容自己决定
        while(iteContent != item.end())
        {
            UIContentBase* contentBase = *iteContent;
            contentBase->changeValue(ChangeValueType(sign));
            iteContent++;
        }
    }
    //show();
}
