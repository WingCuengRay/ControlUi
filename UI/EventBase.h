#ifndef EVENTBASE_H
#define EVENTBASE_H
#include"DetailDefine.h"


class EventBase
{
public:
    virtual void processEvent(EventID,VarList) = 0;
    virtual bool initEvent() = 0;
    virtual void releaseEvent() = 0;
};


#endif // EVENTBASE_H
