
#ifndef _DETAILDEFINE_H
#define _DETAILDEFINE_H

#define TOCHARARRAY(para) #para
#include<vector>
#include "../serial/Frame.h"
using std::vector;

enum class EventType//事件类型
{
    EventTypeInvalid,
    EventTypeRecievePrimaryData,
    EventTypeMain,
    EventTypePanel,
    EventTypePicture,
    EventTypeSound,
};
enum class EventDetail//事件细节
{
    DetailInvalid,
    //调出某个UI
    DetailShowUI,
    DetailChangeValue,
    DetailGoAhead,//next page
    DetailGoBack,//late page
    DetailTurnUp,//turn up
    DetailTurnDown,//turn down
    DetailReceivedData,
    DetailMax,
};
struct EventID//事件ID
{
    EventType type;
    EventDetail detail;
    EventID(){}
    EventID(EventType eventType,EventDetail eventDeatail)
    {
        type = eventType;
        detail = eventDeatail;
    }
};

enum class VarListType//接收的数据类型
{
    Char,Int,
};


struct VarList
{
public:
    int getNum()
    {   return num;    }
    void setNum(int numPara)
    {   num = numPara;  }
    int getSign()
    {   return sign;    }
    int setSign(int signPara)
    {   sign = signPara;    }
private:
    int num;
    int sign;
};

enum class WriteDirection
{
    DirecttionEvent,
    DirectionError,
};

struct SizeBox
{
    int topLeftX;
    int topLeftY;
    int downRightX;
    int downRightY;
    SizeBox():topLeftX(0),
        topLeftY(0),
        downRightX(0),
        downRightY(0){}
};

enum class ContentType
{
    ContentString,ContentInt,ContentBool
};

enum class RankType
{
    RankBox,
};

enum class PageType
{
    PageInvalid,
    PageMain,
    PagePanel,
    PagePicture,
    PageSound,
};

enum ChangeValueType
{
    Bigger,
    Smaller,
    Clear,
};

//enum class DataType
//{
//    DataTypeInvalid = 0,
//    DataTypeTurnUp,
//    DataTypeTurnDown,
//    DataTypeTurnLeft,
//    DataTypeTurnRight,
//    DataTypeMax,
//};

/**
typedef unsigned char uchar;
struct Data
{
	Data(uchar * s = 0) : cmd(0)
	{
		//¸³Öµ¸ø etr
		if(s == 0)
			return;
		for(int i=0; s[i]!=0; i++)
			etr.push_back(s[i]);
	}
	unsigned char cmd;
	std::vector<uchar> etr;
};
**/

#endif
