#ifndef UICONTENTBASE_H
#define UICONTENTBASE_H

#include<string>
using std::string;

#include"DetailDefine.h"



class UIContentBase
{
public:
    virtual void show(const SizeBox) = 0;
    virtual void setValue(void *) = 0;
    virtual UIContentBase* create() = 0;
    virtual void changeValue(ChangeValueType) = 0;
};


class UIContentString:public UIContentBase
{
public:
    UIContentString();
    virtual void show(const SizeBox);
    virtual void setValue(void *newValue);
    virtual UIContentBase* create();
    virtual void changeValue(ChangeValueType);
private:
    void changeValueWhenUIPanelName(ChangeValueType);
private:
    std::string content;

    const UIContentString operator=(const UIContentString &second);
};


class UIContentInt:public UIContentBase
{
public:
    UIContentInt();
    virtual void show(const SizeBox);
    virtual void setValue(void *newValue);
    virtual UIContentBase* create();
    virtual void changeValue(ChangeValueType);
private:
    int content;

    const UIContentInt operator=(const UIContentInt &second);
};

class UIContentBool:public UIContentBase
{
public:
    UIContentBool();
    virtual void show(const SizeBox);
    virtual void setValue(void *newValue);
    virtual UIContentBase* create();
    virtual void changeValue(ChangeValueType);
private:
    bool content;

    const UIContentBool operator=(const UIContentBool &second);
};

#endif // UICONTENTBASE_H

