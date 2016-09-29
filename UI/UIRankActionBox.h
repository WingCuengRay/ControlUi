#ifndef UIRANKACTIONBOX_H
#define UIRANKACTIONBOX_H

#include<vector>
using std::vector;

#include"UIRankAction.h"
#include"DetailDefine.h"


class UIContentBase;


class UIRankActionBoxWithTitle:public UIRankAction
{
public:
    UIRankActionBoxWithTitle();
    virtual ~UIRankActionBoxWithTitle();
    virtual void initRankAction();
public:
    virtual void show();
    virtual UIRankAction* create();
private:
    vector<SizeBox> vecRank;
};

#endif // UIRANKACTIONBOX_H
