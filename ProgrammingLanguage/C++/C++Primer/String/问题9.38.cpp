#include <iostream>
#include <string>
using namespace std;


int main23d1gdg()
{
	string str("ab2c3d7R4E6");
	string numbers("0123456789");
	string letters("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	while ((pos = str.find_first_not_of(letters, pos)) != string::npos)
	{
		cout << str[pos] << " ";
		pos++;
	}
	cout << endl;
	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << str[pos] << " ";
		pos++;
	}

	system("pause");
	return 0;
}



int main231sadf()
{
	string str("ab2c3d7R4E6");
	string numbers("0123456789");
	string letters("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	while ((pos = str.find_first_of(numbers, pos)) != string::npos)
	{
		cout << str[pos] << " ";
		pos++;
	}
	cout << endl;
	pos = 0;
	while ((pos = str.find_first_of(letters, pos)) != string::npos)
	{
		cout << str[pos] << " ";
		pos++;
	}





	system("pause");
	return 0;
}