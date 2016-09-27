#include "table.h"
#include <iostream>
#include <vector>
#include <string>


#define BUFFSIZE 512

using namespace std;

Cmdtable::Cmdtable(string fname = "./table") : 
				pattern("(\\w+)(\\t| )+(\\w+)(\\t| )+(\\d+)(\\s|\\t| )*")
				//需要在最后匹配一个换页符
{
	ifstream in(fname);
	
	if(!in.is_open())
	{
		cout << fname << " not exist.\n";
		cout << "Using default file: ./table" << endl;
		
		in.open("./table", ios::in);
		if(!in.is_open())
		{
			throw("Default file was deleted.\n");
		}
	}
	
	string s;
	while(getline(in, s))
	{
		match_results<string::const_iterator> result;
		bool vaild = std::regex_match(s, result, pattern);
		if(vaild)
		{
			cmd[result[3]] = stoi(result[5]);
			//cout << result[3] << ':' << cmd[result[3]] << endl;
		}
	}
}
