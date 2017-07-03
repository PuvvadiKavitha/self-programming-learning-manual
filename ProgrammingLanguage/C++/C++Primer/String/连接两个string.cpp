#include <iostream>
#include <string>
using namespace std;
int main23dfgd()
{
	string s1("asdfsaf jiayu hello");
	string s2("chengzhi love world");
	string s3;
	s3.assign(s2.begin(), s2.begin() + 14);
	s3.append(s1.substr(s1.find("jiayu"), 5));
	cout << s3 << endl;




	system("pause");
	return 0;
}
