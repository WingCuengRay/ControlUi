#include "UIBase.h"
#include"UIRankAction.h"

UIBase::UIBase():index(0)
{
    //ctor
}

UIBase::~UIBase()
{
    //dtor
}
void UIBase::setRankAndContent(UIRankAction *rankActionPara,VecContentPageType &pageContentPara)
{
    pageContent = pageContentPara;
    rankAction = rankActionPara;
    rankAction->setPageContent(&pageContent);
    rankAction->initRankAction();
}
