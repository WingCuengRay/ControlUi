#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>

using namespace std;





vector< vector<string> > parseFile(string dir)
{
	ifstream fin(dir);
	vector< vector<string> > res;
	
	if( !fin.is_open() )
	{
		cout << "File open error.\n"; 
		return res;
	}
	
	const regex pattern("[^ ,\\t\\s\\n]+");
	string line;
	while(getline(fin, line))
	{
		const std::sregex_token_iterator end;  
		for (std::sregex_token_iterator i(line.begin(),line.end(), pattern); i != end ; ++i)
		{
			std::cout << *i << std::endl;
		}
		/**
		match_results<string::const_iterator> result;
		bool vaild = std::regex_search(line, result, pattern);
		if(vaild)
		{
			for(unsigned int i=0; i<result.size(); i++)
				cout << result[i] << ":";
			cout << endl;
		}
		**/
	}
	
	return res;
}


int main(void)
{
	string s = "./table";
	
	
	auto res = parseFile(s);
	
	return 0;
}