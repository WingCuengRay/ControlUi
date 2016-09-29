#include "DebugTool.h"
#include<iostream>
using std::cout;


DebugTool::DebugTool():SingleatonClass<DebugTool>()
{
    //ctor
}

DebugTool::~DebugTool()
{
    //dtor
}
void DebugTool::outputString(const string para)
{
    string first("1321");
    string second;
#ifdef PLATFORM_WIN32
    cout << para;
#endif // PLATFORM_WIN32
}
void DebugTool::initSingleton()
{

}
