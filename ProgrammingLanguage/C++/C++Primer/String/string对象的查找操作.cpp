#include <iostream>
#include <string>
using namespace std;
int main231dsgdsfg()
{
	string s("chengzhi-Hello-World");
	char cp[] = { 'W', 'o', 'r', 'l', 'd', '\0' };
	cout << s.find('-') << endl;
	cout << s.rfind('-') << endl;
	cout << s.find_first_of('-') << endl;
	cout << s.find_last_of('-') << endl;
	cout << s.find_first_not_of('-') << endl;
	cout << s.find_last_not_of('-') << endl;
	cout << s.find('-', 0) << endl;
	cout << s.find("Hello", 0) << endl;
	cout << s.find(cp, 0) << endl;
	cout << s.find(cp, 0, 5) << endl;



	system("pause");
	return 0;
}
