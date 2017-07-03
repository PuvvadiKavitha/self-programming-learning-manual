#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;
int main897fas()
{
	pair<string, int> ipair;
	string str;
	int ival;
	vector< pair<string, int> > pvec;
	while (cin >> str >> ival)
	{
		//下面提供三种方法
		//ipair = make_pair(str, ival);
		
		//ipair.first = str;
		//ipair.second = ival;
		
		//pair<string, int> ipair_2(str, ival);
		
		pvec.push_back(ipair);
	}

	 
	system("pause");
	return 0;
}
