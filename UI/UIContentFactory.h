#ifndef UICONTENTFACTORY_H
#define UICONTENTFACTORY_H
#include<map>
using std::map;

#include"DetailDefine.h"
#include"SingletonClass.h"
#include"UIContentBase.h"


class UIContentFactory:public SingleatonClass<UIContentFactory>
{
    typedef map<ContentType,UIContentBase*> MapCreate;
public:
    UIContentFactory();
    virtual ~UIContentFactory();

public:
    UIContentBase* create(ContentType type);
    void registerType(ContentType type,UIContentBase*);
    void unRegisterType(ContentType);
public:
    virtual void initSingleton();
private:
    MapCreate mapCreate;
};

class UIContentFactoryHelper
{
public:
    UIContentFactoryHelper(ContentType,UIContentBase&);
};

#define REGISTEREVENT_UICONTENT_TYPE(contentType,className) \
    className content##className; \
    UIContentFactoryHelper contentHelper##className(contentType,content##className);

#endif // UICONTENTFACTORY_H
