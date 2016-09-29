#ifndef GLOBALFUNCTIONDECLARATION_H
#define GLOBALFUNCTIONDECLARATION_H
#include<string>
enum WriteDirection;


void globalWriteFile(const WriteDirection eDirection,const EventID &content);
bool operator<(const EventID &left,const EventID &right);
void initSysterm();
void TestSomthing();
std::string EventIDToString(EventID eventID);
#endif // GLOBALFUNCTIONDECLARATION_H

