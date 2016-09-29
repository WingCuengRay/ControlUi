#include "ImfoManager.h"
#include"UIContentBase.h"
#include"DebugTool.h"
#include"UIContentFactory.h"

ImfoManager::ImfoManager():SingleatonClass<ImfoManager>()
{

}

ImfoManager::~ImfoManager()
{

}
void ImfoManager::initSingleton()
{
    setMainPage();
    setMainPageEventID();
    setPicturePage();
    setPictureEventID();
}


VecContentPageType ImfoManager::getPage(PageType pageName)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    VecContentPageType ret;

    if(mapPageContents.find(pageName) != mapPageContents.end())
    {
        debugTool->outputString("ImfoManager::getPage    get main plane success\n");

        ret = mapPageContents[pageName];
    }
    else
    {
        debugTool->outputString("ImfoManager::getPage    get main plane false false\n");
    }

    return ret;//直接返回局部变量而不返回指针，是不希望外部修改原始数据
}
void ImfoManager::setMainPage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setMainPage    set first page content\n");

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();

    UIContentBase* pValue1 = contentFactory->create(ContentType::ContentInt);
    UIContentBase* pValue2 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue3 = contentFactory->create(ContentType::ContentBool);
    VecContentItemType firstItem,secondItem,threeItem;
    VecContentPageType firstPage;

    string temp("i am title     ");
    pValue2->setValue(&temp);
    firstItem.push_back(pValue2);

    int tempInt = 2;
    pValue1->setValue(&tempInt);
    secondItem.push_back(pValue1);


    bool tempBool = true;
    pValue3->setValue(&tempBool);
    threeItem.push_back(pValue3);

    firstPage.push_back(firstItem);
    firstPage.push_back(secondItem);
    firstPage.push_back(threeItem);

    mapPageContents[PageType::PageMain] = firstPage;
}


void ImfoManager::setMainPageEventID()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setMainPageEventID    set main page event id\n");

    VecEventID vecEventID;
    EventID first,second,third;

    first.type = EventType::EventTypeMain;
    first.detail = EventDetail::DetailShowUI;

    second.type = EventType::EventTypeMain;
    second.detail = EventDetail::DetailTurnUp;


    third.type = EventType::EventTypeMain;
    third.detail = EventDetail::DetailChangeValue;

    vecEventID.push_back(first);
    vecEventID.push_back(second);
    vecEventID.push_back(third);

    pageEventID[PageType::PageMain] = vecEventID;
}

void ImfoManager::setPicturePage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setPicturePage    set first page content\n");

    UIContentFactory* contentFactory = UIContentFactory::getSingleton();
    UIContentBase* pValue = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue21 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue22 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue31 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue32 = contentFactory->create(ContentType::ContentString);

    VecContentItemType firstItem,secondItem,threeItem;
    VecContentPageType firstPage;

    string temp("i am title     ");
    pValue->setValue(&temp);
    firstItem.push_back(pValue);
    firstPage.push_back(firstItem);

    string secondFirst("second1     ");
    pValue21->setValue(&secondFirst);
    secondItem.push_back(pValue21);
    string secondSecond("second2    ");
    pValue22->setValue(&secondSecond);
    secondItem.push_back(pValue22);
    firstPage.push_back(secondItem);

    string threeFirst("threeFirst    ");
    pValue31->setValue(&threeFirst);
    threeItem.push_back(pValue31);
    string threeSecond("threeSecond    ");
    pValue32->setValue(&threeSecond);
    threeItem.push_back(pValue32);
    firstPage.push_back(threeItem);

    mapPageContents[PageType::PagePicture] = firstPage;
}
void ImfoManager::setPictureEventID()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setPictureEventID    \n");

    VecEventID vecEventID;
    EventID first,second,third;

    first.type = EventType::EventTypePicture;
    first.detail = EventDetail::DetailShowUI;

    second.type = EventType::EventTypePicture;
    second.detail = EventDetail::DetailTurnUp;

    third.type = EventType::EventTypePicture;
    third.detail = EventDetail::DetailChangeValue;

    vecEventID.push_back(first);
    vecEventID.push_back(second);
    vecEventID.push_back(third);

    pageEventID[PageType::PagePicture] = vecEventID;
}
void ImfoManager::setPanelPage()
{

}
void ImfoManager::setPanelPageEventID()
{

}
VecEventID ImfoManager::getPageEventID(PageType pageTypePara)
{
    VecEventID ret;
    DebugTool *debugTool = DebugTool::getSingleton();

    if(pageEventID.find(pageTypePara) != pageEventID.end())
    {
        debugTool->outputString("ImfoManager::getPageEventID    success find main eventid\n");
        ret = pageEventID[pageTypePara];
    }
    else
    {
        debugTool->outputString("ImfoManager::getPageEventID    false find main eventid\n");
    }
    return ret;
}



