#ifndef UICONTENTITEM_H
#define UICONTENTITEM_H

#include"DetailDefine.h"
#include<vector>
using std::vector;


class UIContentBase;
class UIRankAction;

class UIContentItem
{
public:
    UIContentItem();
    virtual ~UIContentItem();
    void show(const SizeBox);
protected:
    vector<UIContentBase*> vecContent;
    UIRankAction *rankAction;
};

#endif // UICONTENTITEM_H
