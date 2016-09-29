#include "UIContentBase.h"
#include "DebugTool.h"
#include"UIContentFactory.h"
#include"UITool.h"
#include<cstddef>

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
    case ChangeValueType::Clear:
        content.clear();
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
    return new UIContentInt;//²»»á·µ»ØNULL
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
    case ChangeValueType::Bigger:
        content++;
        break;
    case ChangeValueType::Smaller:
        content--;
        break;
    case ChangeValueType::Clear:
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
    case ChangeValueType::Bigger:
    case ChangeValueType::Smaller:
        content = !content;
        break;
    }
}
REGISTEREVENT_UICONTENT_TYPE(ContentType::ContentBool,UIContentBool);
