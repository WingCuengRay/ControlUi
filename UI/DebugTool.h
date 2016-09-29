#ifndef DEBUGTOOL_H
#define DEBUGTOOL_H

#include"SingletonClass.h"
#include<string>
using std::string;


class DebugTool:public SingleatonClass<DebugTool>
{
public:
    DebugTool();
    virtual ~DebugTool();
    virtual void initSingleton();
public:
    void outputString(const string para);
};

#endif // DEBUGTOOL_H
