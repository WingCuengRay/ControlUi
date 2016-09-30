#include "UITool.h"
#include<iostream>
#include <curses.h>
#include<string>
using std::cout;
using std::endl;
using std::string;

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
    linuxShow(x,y,value);
}
void UITool::show(int x,int y,const int value)
{
#ifdef PLATFORM_WIN32
    win32Show(x,y,value);
    return ;
#endif // PLATFORM_WIN32
    linuxShow(x,y,value);
}
void UITool::refresh()
{
#ifdef PLATFORM_WIN32
    win32Refresh();
    return ;
#endif // PLATFORM_WIN32
    linuxRefresh();
}
void UITool::clearWindow()
{
    linuxClearWindow();
}

void UITool::linuxShow(int x,int y,const char*value)
{
    //move(x, y); /*move the cursor to the center*/
    //waddstr(stdscr, value);
	mvprintw(x,y,"%s",value);
}
void UITool::linuxShow(int x,int y,const int value)
{
    //move(x,y);
    //string temp = std::to_string(value);
    //waddstr(stdscr,temp.c_str());
	mvprintw(x,y,"%d",value);
}
void UITool::linuxRefresh()
{
    ::refresh();
}
void UITool::linuxClearWindow()
{
    ::clear();
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
