#include "UIContentFactory.h"
#include"DebugTool.h"


UIContentFactory::UIContentFactory():SingleatonClass<UIContentFactory>()
{

}

UIContentFactory::~UIContentFactory()
{

}
UIContentBase* UIContentFactory::create(ContentType type)
{
    UIContentBase* ret = nullptr;
    DebugTool *debugTool = DebugTool::getSingleton();
    if(mapCreate.find(type) != mapCreate.end())
    {
        debugTool->outputString("UIContentFactory::create    success\n");
        UIContentBase* temp = mapCreate[type];
        ret = temp->create();
    }
    else
    {
        debugTool->outputString("UIContentFactory::create    false\n");
    }
    return ret;
}
void UIContentFactory::registerType(ContentType type,UIContentBase* newBase)
{
    //还没有进入main就是用cout，会出错
    DebugTool *debugTool;
    debugTool = DebugTool::getSingleton();
    if(mapCreate.find(type) == mapCreate.end())
    {
        //debugTool->outputString("UIContentFactory::registerType   success\n");
        mapCreate[type] = newBase;
    }
    else
    {
        //debugTool->outputString("UIContentFactory::registerType   false false false\n");
    }
}
void UIContentFactory::unRegisterType(ContentType contentType)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    if(mapCreate.find(contentType) != mapCreate.end())
    {
        debugTool->outputString("UIContentFactory::unRegisterType    success\n");
        mapCreate.erase(contentType);
    }
    else
    {
        debugTool->outputString("UIContentFactory::unRegisterType    false false false\n");
    }
}

void UIContentFactory::initSingleton()
{

}

UIContentFactoryHelper::UIContentFactoryHelper(ContentType contentType,UIContentBase& contentBase)
{
    UIContentFactory *factory = UIContentFactory::getSingleton();
    factory->registerType(contentType,&contentBase);
}
