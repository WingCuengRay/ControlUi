#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

template <typename TrueType>
class SingleatonClass
{
public:
    SingleatonClass()
    {
    }

    static TrueType* getSingleton()
    {
        static TrueType *singletonObject = 0;
        if(singletonObject == 0)
            singletonObject = new TrueType;
        return singletonObject;
    }
    virtual void initSingleton() = 0;
};

#endif // SINGLETONCLASS_H
