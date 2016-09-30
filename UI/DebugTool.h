#ifndef DEBUGTOOL_H
#define DEBUGTOOL_H

#include"SingletonClass.h"
#include<string>
using std::string;
#ifndef PLATFORM_WIN32
#define PLATFORM_LINUX
#endif // PLATFORM_WIN32

class DebugTool:public SingleatonClass<DebugTool>
{
public:
    DebugTool();
    virtual ~DebugTool();
    virtual void initSingleton();
public:
    void outputString(const string para);
    void newOutput(const string para);
};

#endif // DEBUGTOOL_H
