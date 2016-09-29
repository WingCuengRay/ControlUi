#ifndef SYSTERMMANAGER_H
#define SYSTERMMANAGER_H
#include"SingletonClass.h"


class EventManager;
class SystermManager:public SingleatonClass<SystermManager>
{
public:
    SystermManager();
    virtual ~SystermManager();

private:
    EventManager* eventManager;

};

#endif // SYSTERMMANAGER_H
