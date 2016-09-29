#ifndef _GLOBALFUNCTION_CPP_
#define _GLOBALFUNCTION_CPP_

#include<fstream>
#include<string>
#include"DetailDefine.h"
#include"UIManager.h"
#include"ImfoManager.h"
#include"DebugTool.h"
#include"UITool.h"
#include"EventManager.h"
#include"UIContentFactory.h"
#include"UIRankFactory.h"
#include"MessageManager.h"

//将事件的ID转换为连续的字符串
std::string EventIDToString(EventID eventID)
{
    std::string ret;
    switch(eventID.type)
    {
    case EventType::EventTypePanel:
        ret += TOCHARARRAY(EventType::EventTypePanel);
        break;
    case EventType::EventTypeSound:
        ret += TOCHARARRAY(EventType::EventTypeSound);
        break;
    case EventType::EventTypePicture:
        ret += TOCHARARRAY(EventType::EventTypePicture);
        break;
    case EventType::EventTypeMain:
        ret += TOCHARARRAY(EventType::EventTypeMain);
        break;
    case EventType::EventTypeRecievePrimaryData:
        ret += TOCHARARRAY(EventType::EventTypeRecievePrimaryData);
        break;
    }
    ret += "\t\t";
    switch(eventID.detail)
    {
    //case EventDetail::DetailFirst:
    //   ret += TOCHARARRAY(EventDetail::DetailFirst);
    //   break;
    case EventDetail::DetailChangeValue:
        ret += TOCHARARRAY(EventDetail::DetailChangeValue);
        break;
    case EventDetail::DetailGoAhead:
        ret += TOCHARARRAY(EventDetail::DetailGoAhead);
        break;
    case EventDetail::DetailGoBack:
        ret += TOCHARARRAY(EventDetail::DetailGoBack);
        break;
    case EventDetail::DetailInvalid:
        ret += TOCHARARRAY(EventDetail::DetailInvalid);
        break;
    case EventDetail::DetailMax:
        ret += TOCHARARRAY(EventDetail::DetailMax);
        break;
    case EventDetail::DetailReceivedData:
        ret += TOCHARARRAY(EventDetail::DetailReceivedData);
        break;
    case EventDetail::DetailShowUI:
        ret += TOCHARARRAY(EventDetail::DetailShowUI);
        break;
    case EventDetail::DetailTurnDown:
        ret += TOCHARARRAY(EventDetail::DetailTurnDown);
        break;
    case EventDetail::DetailTurnUp:
        ret += TOCHARARRAY(EventDetail::DetailTurnUp);
        break;
    }
    return ret;
}



// bug! Linux 下错误
#define EventFileName TOCHARARRAY(./Event.txt)
#define ErrorFileName TOCHARARRAY(./Error.txt)
static void writeFile(const std::string &fileName,const EventID &EventID)
{

//外部可调用的输出到文件接口
    //此部分是在wind32下调试
#ifdef PLATFORM_WIN32
    std::fstream file(fileName,std::fstream::app);
    if(!file)
    {
        std::fstream errorFile(ErrorFileName,std::fstream::app);
        errorFile << "can't open file " << fileName << "\n";
        errorFile.close();
        return;
    }

    file << EventIDToString(EventID) << "\n";
    file.close();
#endif // PLATFORM_WIN32
}

void globalWriteFile(const WriteDirection eDirection,const EventID &content)
{
#ifdef PLATFORM_WIN32
    using namespace std;
    switch(eDirection)
    {
    case WriteDirection::DirecttionEvent:
        writeFile(EventFileName,content);
        break;
    case WriteDirection::DirectionError:
        writeFile(ErrorFileName,content);
        break;
    }
#endif // PLATFORM_WIN32
}

bool operator<(const EventID &left,const EventID &right)
{
    if(left.type < right.type)
        return true;
    else if(left.type > right.type)
        return false;
    else
    {
        if(left.detail < right.detail)
            return true;
        else if(left.detail <= right.detail)
            return false;
    }
    return false;
}


void initSysterm()
{
    EventManager *eventManager = EventManager::getSingleton();
    eventManager->initSingleton();

    MessageManager *messageManager = MessageManager::getSingleton();
    messageManager->initSingleton();

    ImfoManager* imfoManager = ImfoManager::getSingleton();
    imfoManager->initSingleton();


    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->initSingleton();

    UITool *uiTool = UITool::getSingleton();
    uiTool->initSingleton();

    UIManager* uiManager = UIManager::getSingleton();
    uiManager->initSingleton();
}


void TestSomthing()
{
    EventID eventID(EventType::EventTypeMain,EventDetail::DetailChangeValue);
    VarList varList;
    varList.setNum(1);
    varList.setSign(int(ChangeValueType::Bigger));
    EventManager *eventManger = EventManager::getSingleton();
    eventManger->sendEvent(eventID,varList);


    eventID.type = EventType::EventTypeRecievePrimaryData;
    eventID.detail = EventDetail::DetailReceivedData;
    varList.setNum(2);
    eventManger->sendEvent(eventID,varList);


    Data data;
    data.cmd = 3;
    MessageManager *messageManager = MessageManager::getSingleton();
    messageManager->sendMessage(data);//--------------
    messageManager->update();//------------------------
}
#endif // _GLOBALFUNCTION_H_
