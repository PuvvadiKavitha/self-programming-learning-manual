#include <iostream>
#include <string>
using namespace std;
int main21sdfs()
{
	char *cp = "chengzhi";
	string s(cp, 8);
	cout << s << endl;
	string s2(s, 5);
	cout << s2 << endl;
	string s3(s, 0, 5);
	cout << s3 << endl;

	system("pause");
	return 0;
}
