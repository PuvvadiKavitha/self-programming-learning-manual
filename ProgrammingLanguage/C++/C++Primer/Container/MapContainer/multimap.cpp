#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
using namespace std;
int main()
{
	string book("K&R C");
	multimap<string, string> authors;
	typedef multimap<string, string>::iterator iter;
	iter iter_begin = authors.lower_bound(book);
	iter iter_end = authors.upper_bound(book);
	while (iter_begin != iter_end)
	{
		cout << iter_begin->second << endl;
		iter_begin++;
	}


	pair<iter, iter> pos = authors.equal_range(book);
	while (pos.first != pos.second)
	{
		cout << pos.first->first << ":" << pos.first->second << endl;
		(pos.first)++;
	}




	system("pause");
	return 0;
}