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
//����Ϊwin32���нӿ�----------------------------

private:
    void win32Show(int x,int y,const char*);
    void win32Show(int x,int y,const int);
    void win32Refresh();
//win32�ӿڵ��˽���------------------------------
};

#endif // UITOOL_H
