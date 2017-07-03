#include <iostream>
#include <string>
using namespace std;
int main321sadfs()
{
	string s("chengzhi");
	string s2("Hello");
	cout << s.substr(0, 5) << endl;
	cout << s.substr(5) << endl;
	cout << s << endl;
	cout << s.append(s2) << endl;
	cout << s.replace(0, 8, s2) << endl;
	cout << s.replace(s.begin(), s.end(), s2) << endl;



	system("pause");
	return 0;
}
