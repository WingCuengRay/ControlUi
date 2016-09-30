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
    setPanelPage();
    setPanelPageEventID();
    setSoundPage();
    setSoundPageEventID();
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

    UIContentBase* pValueTitle = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueName = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueFunc = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue11 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue12 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue21 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue22 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue31 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue32 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue41 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue42 = contentFactory->create(ContentType::ContentBool);


    string title("Main Page");
    string name("Name");
    string func("Function");
    string content11("Picture"),content12(">>>");
    string content21("Panel"),content22(">>>");
    string content31("Sound"),content32(">>>");
    string content41("Debug");
    bool content42(false);

    pValueTitle->setValue(&title);
    pValueName->setValue(&name);
    pValueFunc->setValue(&func);
    pValue11->setValue(&content11);
    pValue12->setValue(&content12);
    pValue21->setValue(&content21);
    pValue22->setValue(&content22);
    pValue31->setValue(&content31);
    pValue32->setValue(&content32);
    pValue41->setValue(&content41);
    pValue42->setValue(&content42);

    VecContentItemType itemTitle,itemName,itemPicture,itemPanel,itemSound,itemDebug;
    itemTitle.push_back(pValueTitle);
    itemName.push_back(pValueName);
    itemName.push_back(pValueFunc);
    itemPicture.push_back(pValue11);
    itemPicture.push_back(pValue12);
    itemPanel.push_back(pValue21);
    itemPanel.push_back(pValue22);
    itemSound.push_back(pValue31);
    itemSound.push_back(pValue32);
    itemDebug.push_back(pValue41);
    itemDebug.push_back(pValue42);

    VecContentPageType firstPage;
    firstPage.push_back(itemTitle);
    firstPage.push_back(itemName);
    firstPage.push_back(itemPicture);
    firstPage.push_back(itemPanel);
    firstPage.push_back(itemSound);
    firstPage.push_back(itemDebug);

    mapPageContents[PageType::PageMain] = firstPage;
}


void ImfoManager::setMainPageEventID()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setMainPageEventID    set main page event id\n");

    VecEventID vecEventID;
    EventID first,second;

    first.type = EventType::EventTypeMain;
    first.detail = EventDetail::DetailShowUI;

    second.type = EventType::EventTypeMain;
    second.detail = EventDetail::DetailChangeValue;

    vecEventID.push_back(first);
    vecEventID.push_back(second);

    pageEventID[PageType::PageMain] = vecEventID;
}

void ImfoManager::setPicturePage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setMainPage    set first page content\n");

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();

    UIContentBase* pValueTitle = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueName = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueFunc = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue11 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue12 = contentFactory->create(ContentType::ContentInt);
    UIContentBase* pValue21 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue22 = contentFactory->create(ContentType::ContentInt);


    string title("Picture Page");
    string name("Name");
    string func("Function");
    string content11("Brightness");
    int content12(0);
    string content21("Contrast");
    int content22(0);

    pValueTitle->setValue(&title);
    pValueName->setValue(&name);
    pValueFunc->setValue(&func);
    pValue11->setValue(&content11);
    pValue12->setValue(&content12);
    pValue21->setValue(&content21);
    pValue22->setValue(&content22);

    VecContentItemType itemTitle,itemName,itemBrightness,itemContrast;
    itemTitle.push_back(pValueTitle);
    itemName.push_back(pValueName);
    itemName.push_back(pValueFunc);
    itemBrightness.push_back(pValue11);
    itemBrightness.push_back(pValue12);
    itemContrast.push_back(pValue21);
    itemContrast.push_back(pValue22);

    VecContentPageType firstPage;
    firstPage.push_back(itemTitle);
    firstPage.push_back(itemName);
    firstPage.push_back(itemBrightness);
    firstPage.push_back(itemContrast);

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
    second.detail = EventDetail::DetailChangeValue;

    vecEventID.push_back(first);
    vecEventID.push_back(second);

    pageEventID[PageType::PagePicture] = vecEventID;
}
void ImfoManager::setPanelPage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setMainPage    set first page content\n");

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();

    UIContentBase* pValueTitle = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueName = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueFunc = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue11 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue12 = contentFactory->create(ContentType::ContentBool);
    UIContentBase* pValue21 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue22 = contentFactory->create(ContentType::ContentBool);


    string title("Panel Page");
    string name("Name");
    string func("Function");
    string content11("Panel On");
    bool content12(false);
    string content21("BacklLight On");
    bool content22(false);

    pValueTitle->setValue(&title);
    pValueName->setValue(&name);
    pValueFunc->setValue(&func);
    pValue11->setValue(&content11);
    pValue12->setValue(&content12);
    pValue21->setValue(&content21);
    pValue22->setValue(&content22);

    VecContentItemType itemTitle,itemName,itemPanelOn,itemBackLight;
    itemTitle.push_back(pValueTitle);
    itemName.push_back(pValueName);
    itemName.push_back(pValueFunc);
    itemPanelOn.push_back(pValue11);
    itemPanelOn.push_back(pValue12);
    itemBackLight.push_back(pValue21);
    itemBackLight.push_back(pValue22);

    VecContentPageType firstPage;
    firstPage.push_back(itemTitle);
    firstPage.push_back(itemName);
    firstPage.push_back(itemPanelOn);
    firstPage.push_back(itemBackLight);

    mapPageContents[PageType::PagePanel] = firstPage;
}
void ImfoManager::setPanelPageEventID()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setPictureEventID    \n");

    VecEventID vecEventID;
    EventID first,second,third;

    first.type = EventType::EventTypePanel;
    first.detail = EventDetail::DetailShowUI;

    second.type = EventType::EventTypePanel;
    second.detail = EventDetail::DetailChangeValue;

    vecEventID.push_back(first);
    vecEventID.push_back(second);

    pageEventID[PageType::PagePanel] = vecEventID;
}
void ImfoManager::setSoundPage()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setMainPage    set first page content\n");

    UIContentFactory *contentFactory = UIContentFactory::getSingleton();

    UIContentBase* pValueTitle = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueName = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValueFunc = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue11 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue12 = contentFactory->create(ContentType::ContentInt);
    UIContentBase* pValue21 = contentFactory->create(ContentType::ContentString);
    UIContentBase* pValue22 = contentFactory->create(ContentType::ContentInt);
    UIContentBase *pValue31 = contentFactory->create(ContentType::ContentString);
    UIContentBase *pValue32 = contentFactory->create(ContentType::ContentInt);

    string title("Sound Page");
    string name("Name");
    string func("Function");
    string content11("Treble");
    int content12(0);
    string content21("Bass");
    int content22(0);
    string content31("Balance");
    int content32(0);

    pValueTitle->setValue(&title);
    pValueName->setValue(&name);
    pValueFunc->setValue(&func);
    pValue11->setValue(&content11);
    pValue12->setValue(&content12);
    pValue21->setValue(&content21);
    pValue22->setValue(&content22);
    pValue31->setValue(&content31);
    pValue32->setValue(&content32);

    VecContentItemType itemTitle,itemName,itemTreble,itemBase,itemBalance;
    itemTitle.push_back(pValueTitle);
    itemName.push_back(pValueName);
    itemName.push_back(pValueFunc);
    itemTreble.push_back(pValue11);
    itemTreble.push_back(pValue12);
    itemBase.push_back(pValue21);
    itemBase.push_back(pValue22);
    itemBalance.push_back(pValue31);
    itemBalance.push_back(pValue32);

    VecContentPageType firstPage;
    firstPage.push_back(itemTitle);
    firstPage.push_back(itemName);
    firstPage.push_back(itemTreble);
    firstPage.push_back(itemBase);
    firstPage.push_back(itemBalance);

    mapPageContents[PageType::PageSound] = firstPage;
}
void ImfoManager::setSoundPageEventID()
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("ImfoManager::setPictureEventID    \n");

    VecEventID vecEventID;
    EventID first,second,third;

    first.type = EventType::EventTypeSound;
    first.detail = EventDetail::DetailShowUI;

    second.type = EventType::EventTypeSound;
    second.detail = EventDetail::DetailChangeValue;

    vecEventID.push_back(first);
    vecEventID.push_back(second);

    pageEventID[PageType::PageSound] = vecEventID;
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



