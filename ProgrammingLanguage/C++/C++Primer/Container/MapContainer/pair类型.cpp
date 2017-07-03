#include <iostream>
#include <utility>
using namespace std;
int main321dsfgds()
{
	pair<int, int> ipair;
	pair<int, int> ipair_2(10, 20);
	ipair = make_pair(20, 30);
	cout << ipair.first << endl;
	cout << ipair.second<< endl;
	cout << ipair_2.first << endl;
	cout << ipair_2.second << endl;

	//cout << ipair_2 < ipair << endl;
	system("pause");
	return 0;
}
