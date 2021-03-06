#ifndef UITOOL_H
#define UITOOL_H

#include"SingletonClass.h"

class UITool:public SingleatonClass<UITool>
{
public:
    UITool();
    virtual ~UITool();
    virtual void initSingleton();
public:
    void show(int x,int y,const char*);
    void show(int x,int y,const int);
    void refresh();
    void clearWindow();
//以下为win32特有接口----------------------------

private:
    void win32Show(int x,int y,const char*);
    void win32Show(int x,int y,const int);
    void win32Refresh();
private:
    void linuxShow(int x,int y,const char*);
    void linuxShow(int x,int y,const int);
    void linuxRefresh();
    void linuxClearWindow();
//win32接口到此结束------------------------------
};

#endif // UITOOL_H
