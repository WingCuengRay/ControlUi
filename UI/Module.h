#ifndef MODULE_H
#define MODULE_H


class Module
{
public:
    Module();
    virtual ~Module();
    virtual void init() = 0;
};

#endif // MODULE_H
