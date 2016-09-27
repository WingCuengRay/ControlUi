#ifndef __TABLE_H
#define __TABLE_H

#include <map>
#include <string>
#include <fstream>
#include <regex>

class Cmdtable
{
public:
	Cmdtable(std::string fname);
	const std::map<std::string, int>& getTable() const
	{
		return cmd;
	}

private:
	std::map<std::string, int> cmd;
	const std::regex pattern;
};


#endif