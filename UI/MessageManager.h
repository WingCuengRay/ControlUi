#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include"SingletonClass.h"
#include"DetailDefine.h"

#include<vector>
using std::vector;



class MessageManager:public SingleatonClass<MessageManager>
{
public:
    MessageManager();
    virtual ~MessageManager();

    virtual void initSingleton();
public:
    void sendMessage(Data);
    void update(float deltaTime = 0.05);
private:
    vector<Data> vecMessage;
};

#endif // MESSAGEMANAGER_H
