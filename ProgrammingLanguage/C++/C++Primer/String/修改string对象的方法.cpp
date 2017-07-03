#include <iostream>
#include <string>
using namespace std;
int main321sdafs()
{
	char cp[] = { 'w', 'o', 'r', 'l', 'd', '\0' };
	string s("chengzhi");
	string s2("Hello");
	cout << s << endl;
	s.insert(s.begin(), 'c');
	cout << s << endl;
	s.insert(s.begin(), 3, 'c');
	cout << s << endl;
	s.insert(s.begin(), s2.begin(), s2.end());
	cout << s << endl;
	s.assign(s2.begin(), s2.end());
	cout << s << endl;
	s.assign(10, 'H');
	cout << s << endl;
	s.erase(s.begin());
	cout << s << endl;
	s.erase(s.begin(), s.end());
	cout << s << endl;
	s.insert(0, 5, 'C');
	cout << s << endl;
	s.insert(1, s2);
	cout << s << endl;
	s.insert(0, s2, 2, 3);
	cout << s << endl;
	s.insert(0, cp, 5);
	cout << s << endl;
	s.insert(0, cp);
	cout << s << endl;
	s.assign(cp);
	cout << s << endl;
	s.assign(s2, 0, 2);
	cout << s << endl;
	s.assign(cp, 2);
	cout << s << endl;
	s.assign(cp);
	cout << s << endl;
	s.erase(0, 2);
	cout << s << endl;
	system("pause");
	return 0;
}
