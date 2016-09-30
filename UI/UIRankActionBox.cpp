#include"UIRankActionBox.h"
#include"DebugTool.h"
#include"UIContentBase.h"
#include"UIRankFactory.h"


UIRankActionBoxWithTitle::UIRankActionBoxWithTitle()
{

}

UIRankActionBoxWithTitle::~UIRankActionBoxWithTitle()
{

}
void UIRankActionBoxWithTitle::show()
{
    vector<SizeBox>::iterator iteRank = vecRank.begin();
    VecContentPageType::iterator iteItem = pageContent->begin();
    bool rankBiggerContent = true;
    while(iteRank != vecRank.end() && iteItem != pageContent->end())
    {
        VecContentItemType vecContent = *iteItem;
        VecContentItemType::iterator iteContent = vecContent.begin();
        while(iteContent != vecContent.end())
        {
            SizeBox boxTemp = *iteRank;
            UIContentBase* contentTemp = *iteContent;
            contentTemp->show(boxTemp);
            iteContent++;
            iteRank++;
        }
        iteItem++;
    }
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIRankActionBoxWithTitle::show \n");
}

UIRankAction* UIRankActionBoxWithTitle::create()
{
    UIRankAction* newObject = new UIRankActionBoxWithTitle;
    return newObject;
}

void UIRankActionBoxWithTitle::initRankAction()
{
    int highRow = 3;
    int highColumn = 20;
    int firstRow = 5;
    int firstColumn = 5;
    SizeBox temp;
    temp.topLeftX = firstRow;
    temp.topLeftY = firstColumn;
    vecRank.push_back(temp);
    for(int row = 0;row < 6;row++)
    {
        for(int column = 0;column < 2;column++)
        {
            temp.topLeftX = firstRow + highRow * (row + 1);
            temp.topLeftY = firstColumn + highColumn * column;
            vecRank.push_back(temp);
        }
    }
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIRankActionBoxWithTitle::initRankAction \n");
}

int UIRankActionBoxWithTitle::getLineX(int num)
{
    if(num > vecRank.size() * 2)
        return 0;
    int position = num * 2;
    if(num > 1)
        position -= num - 1;
    SizeBox temp = vecRank[position];
    return temp.topLeftX;
}
int UIRankActionBoxWithTitle::getLineY(int num)
{
    if(num > vecRank.size() * 2)
        return 0;
    int position = num * 2;
    if(num > 1)
        position -= num - 1;
    SizeBox temp = vecRank[position];
    return temp.topLeftY;
}
REGISTEREVENT_RANK_TYPE(RankType::RankBox,UIRankActionBoxWithTitle);
