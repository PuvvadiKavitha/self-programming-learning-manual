#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int mainfg3h1dg()
{
	string str("Hello Chengzhi, Hello World");
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (isupper(*it))
		{
			it = str.erase(it);
			it--;
		}
		
	}


	cout << str.c_str();



	system("pause");
	return 0;
}
