#include "UIContentBase.h"
#include "DebugTool.h"
#include"UIContentFactory.h"
#include"UITool.h"
#include<cstddef>
#include"EventManager.h"
/*---------------------------------------------
* UIContentString
*---------------------------------------------*/
UIContentString::UIContentString()
{

}
void UIContentString::show(const SizeBox sizeBox)
{
    DebugTool* debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIContentString::show outpt string\t");
    debugTool->outputString(content);
    UITool *uiTool = UITool::getSingleton();
    uiTool->show(sizeBox.topLeftX,sizeBox.topLeftY,content.c_str());
}
void UIContentString::setValue(void *newValue)
{
    if(nullptr != newValue)
        content = *(static_cast<string*>(newValue));
}
UIContentBase* UIContentString::create()
{
    UIContentBase *newObject = new UIContentString();
    return newObject;
}

const UIContentString UIContentString::operator=(const UIContentString &second)
{
    content = second.content;
    return *this;
}
void UIContentString::changeValue(ChangeValueType type)
{
    switch(type)
    {
    case ChangeValueType::ChangeValueTypeClear:
        content.clear();
        break;
    case ChangeValueType::ChangeValueTypeBigger:
    case ChangeValueType::ChangeValueTypeSmaller:
        changeValueWhenUIPanelName(type);
        break;
    }
}

static void sendEventShowUI(EventType type)
{
    EventID eventID(type,EventDetail::DetailShowUI);
    EventManager *eventManger = EventManager::getSingleton();
    VarList temp;
    eventManger->sendEvent(eventID,temp);
}
void UIContentString::changeValueWhenUIPanelName(ChangeValueType type)
{
    bool right = false;
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString(content.c_str());
    right = right || (content == "Panel");
    right = right || (content == "Picture");
    right = right || (content == "Sound");
    right = right || (content == "Main");
    string temp = content;
    if(!right)
        return ;
    switch(type)
    {
    case ChangeValueType::ChangeValueTypeBigger:
        if(content == "Panel")
            sendEventShowUI(EventType::EventTypePanel);
        else if(content == "Picture")
            sendEventShowUI(EventType::EventTypePicture);
        else if(content == "Sound")
            sendEventShowUI(EventType::EventTypeSound);
        break;
    case ChangeValueType::ChangeValueTypeClear:
        break;
    case ChangeValueType::ChangeValueTypeSmaller:
        if(content == "Main")
            sendEventShowUI(EventType::EventTypeMain);
        break;
    }
}
REGISTEREVENT_UICONTENT_TYPE(ContentType::ContentString,UIContentString)


/*---------------------------------------------
* UIContentInt
*---------------------------------------------*/
UIContentInt::UIContentInt():content(0)
{

}
void UIContentInt::show(const SizeBox sizeBox)
{
    UITool* uiTool = UITool::getSingleton();
    uiTool->show(sizeBox.topLeftX,sizeBox.topLeftY,content);
}
void UIContentInt::setValue(void *newValue)
{
    content = *(static_cast<int*>(newValue));
}
UIContentBase* UIContentInt::create()
{
    return new UIContentInt;
}

const UIContentInt UIContentInt::operator=(const UIContentInt &second)
{
    content = second.content;
    return *this;
}
void UIContentInt::changeValue(ChangeValueType type)
{
    switch(type)
    {
    case ChangeValueType::ChangeValueTypeBigger:
        content++;
        break;
    case ChangeValueType::ChangeValueTypeSmaller:
        content--;
        break;
    case ChangeValueType::ChangeValueTypeClear:
        content = 0;
        break;
    }
}

REGISTEREVENT_UICONTENT_TYPE(ContentType::ContentInt,UIContentInt)


/*---------------------------------------------
* UIContentBool
*---------------------------------------------*/
UIContentBool::UIContentBool():content(false)
{

}
void UIContentBool::show(const SizeBox sizeBox)
{
    UITool* uiTool = UITool::getSingleton();
    if(false == content)
        uiTool->show(sizeBox.topLeftX,sizeBox.topLeftY,"false");
    else if(true == content)
        uiTool->show(sizeBox.topLeftX,sizeBox.topLeftY,"true");
}
void UIContentBool::setValue(void *newValue)
{
    content = *(static_cast<bool*>(newValue));
}
UIContentBase* UIContentBool::create()
{
    return new UIContentBool;
}
const UIContentBool UIContentBool::operator=(const UIContentBool &second)
{
    content = second.content;
}
void UIContentBool::changeValue(ChangeValueType type)
{
    switch(type)
    {
    case ChangeValueType::ChangeValueTypeBigger:
    case ChangeValueType::ChangeValueTypeSmaller:
        content = !content;
        break;
    }
}
REGISTEREVENT_UICONTENT_TYPE(ContentType::ContentBool,UIContentBool);
