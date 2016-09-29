#ifndef UIRANKFACTORY_H
#define UIRANKFACTORY_H

#include<map>
using std::map;

#include"DetailDefine.h"
#include"SingletonClass.h"
#include"UIRankAction.h"


class UIRankFactory:public SingleatonClass<UIRankFactory>
{
    typedef map<RankType,UIRankAction*> MapCreate;
public:
    UIRankFactory();
    virtual ~UIRankFactory();

public:
    UIRankAction* create(RankType type);
    void registerType(RankType type,UIRankAction*);
    void unRegisterType(RankType);
public:
    virtual void initSingleton();
private:
    MapCreate mapCreate;
};

class UIRankFactoryHelper
{
public:
    UIRankFactoryHelper(RankType,UIRankAction&);
};

#define REGISTEREVENT_RANK_TYPE(rankType,className) \
    className rank##className; \
    UIRankFactoryHelper rankHelper##className(rankType,rank##className);

#endif // UIRANKFACTORY_H
