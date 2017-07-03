#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main2d1f3sadfwer()
{
	stack<string> ss;
	string str;
	while (cin >> str)
	{
		ss.push(str);
	}
	cout << ss.size() << endl;
	cout << ss.top() << endl;
	ss.pop();
	cout << ss.top() << endl;
	cout << !ss.empty() << endl;

	system("pause");
	return 0;
}
