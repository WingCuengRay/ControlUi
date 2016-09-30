#include "UIBase.h"
#include"UIRankAction.h"

UIBase::UIBase():index(2),
    pageType(PageType::PageInvalid),
    signX(0),
    signY(0)
{
    //ctor
}

UIBase::~UIBase()
{
    //dtor
}
void UIBase::setRankAndContent(UIRankAction *rankActionPara,UIContentBase*signPara,VecContentPageType &pageContentPara)
{
    pageContent = pageContentPara;
    rankAction = rankActionPara;
    rankAction->setPageContent(&pageContent);
    rankAction->initRankAction();
    signContent = signPara;
    signX = rankAction->getLineX(2);
    signY = rankAction->getLineY(2) - 2;
}

void UIBase::setIndex(int num)
{
    index = num;
}
int UIBase::getIndex()
{
    return index;
}
PageType UIBase::getPageType()
{
    return pageType;
}

EventType UIBase::pageTypeToEventType(PageType type)
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
