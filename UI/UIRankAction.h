#ifndef UIRANKACTION_H
#define UIRANKACTION_H

#include<vector>
using std::vector;
class UIContentBase;

class UIRankAction
{
protected:
    typedef vector<UIContentBase*> VecContentItemType;
    typedef vector<VecContentItemType> VecContentPageType;

public:
    UIRankAction();
    virtual ~UIRankAction();
public:
    virtual void show() = 0;
    virtual void initRankAction() = 0;
    virtual UIRankAction* create() = 0;
    virtual int getLineX(int) = 0;
    virtual int getLineY(int) = 0;
public:
    virtual void setPageContent(VecContentPageType *para);

protected:
    VecContentPageType *pageContent;

};

#endif // UIRANKACTION_H
