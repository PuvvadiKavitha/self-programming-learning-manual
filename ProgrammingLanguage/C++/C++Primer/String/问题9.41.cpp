#include <iostream>
#include <string>
using namespace std;

string greet(string form, string lastname, string title, string::size_type pos, int length)
{
	string::iterator iter_begin;
	string::iterator iter_end;

	iter_begin = form.begin() + form.find("Daisy");
	iter_end = iter_begin + 5;
	form.replace(iter_begin, iter_end, lastname);

	iter_begin = form.begin() + form.find("Ms");
	iter_end = iter_begin + 2;
	form.replace(iter_begin, iter_end, title.substr(pos, length));

	return form;
}

int main()
{

	string s1("Dear Ms Daisy");
	string s2("MrsMsMissPeople");
	string lastname("Annap");
	string salute = greet(s1, lastname, s2, 5, 4);
	cout << salute << endl;



	system("pause");
	return 0;
}
