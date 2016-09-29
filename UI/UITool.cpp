#include "UITool.h"
#include<iostream>
using std::cout;
using std::endl;

UITool::UITool():SingleatonClass<UITool>()
{

}

UITool::~UITool()
{

}
void UITool::initSingleton()
{

}
void UITool::show(int x,int y,const char* value)
{

#ifdef PLATFORM_WIN32
    win32Show(x,y,value);
    return;
#endif // PLATFORM_WIN32
}
void UITool::show(int x,int y,const int value)
{
#ifdef PLATFORM_WIN32
    win32Show(x,y,value);
    return ;
#endif // PLATFORM_WIN32
}
void UITool::refresh()
{
#ifdef PLATFORM_WIN32
    win32Refresh();
    return ;
#endif // PLATFORM_WIN32
}
/*--------------------------------------------
* 以下部分为win32特有接口
---------------------------------------------*/

void UITool::win32Show(int x,int y,const char* value)
{
    cout << endl << x << " " << y << " " << value << endl;
}
void UITool::win32Show(int x,int y,const int value)
{
    cout << endl << x << " " << y << " " << value << endl;
}
void UITool::win32Refresh()
{
    cout << "windows has been refresh " << endl;
}
