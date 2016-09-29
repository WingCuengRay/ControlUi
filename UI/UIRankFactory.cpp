#include "UIRankFactory.h"
#include"DebugTool.h"

UIRankFactory::UIRankFactory():SingleatonClass<UIRankFactory>()
{

}

UIRankFactory::~UIRankFactory()
{

}
UIRankAction* UIRankFactory::create(RankType type)
{
    UIRankAction* ret = nullptr;
    DebugTool *debugTool = DebugTool::getSingleton();
    if(mapCreate.find(type) != mapCreate.end())
    {
        debugTool->outputString("UIRankFactory::create    success\n");
        UIRankAction* temp = mapCreate[type];
        ret = temp->create();
    }
    else
    {
        debugTool->outputString("UIRankFactory::create    false\n");
    }
    return ret;
}
void UIRankFactory::registerType(RankType type,UIRankAction* newBase)
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
void UIRankFactory::unRegisterType(RankType rankType)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    if(mapCreate.find(rankType) != mapCreate.end())
    {
        debugTool->outputString("UIRankFactory::unRegisterType    success\n");
        mapCreate.erase(rankType);
    }
    else
    {
        debugTool->outputString("UIRankFactory::unRegisterType    false false false\n");
    }
}

void UIRankFactory::initSingleton()
{

}

UIRankFactoryHelper::UIRankFactoryHelper(RankType rankType,UIRankAction& rankAction)
{
    UIRankFactory *factory = UIRankFactory::getSingleton();
    factory->registerType(rankType,&rankAction);
}

