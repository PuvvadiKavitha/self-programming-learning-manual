#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
using namespace std;


int main465dfgd()
{
	map<string, int> m;
	string word;
	while (cin >> word)
	{
		pair<map<string, int>::iterator, bool> ipair = m.insert(make_pair(word, 1));
		if (!ipair.second)
		{
			(ipair.first->second)++;
		}
	}
	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
	{
		cout << (*iter).first << "-" << (*iter).second << endl;
	}
	m.erase("chengzhi"); 
	m.erase(m.begin(), m.end());

	system("pause");
	return 0;
}



int main2313fgj()
{
	map<string, int> m;
	string word;
	while (cin >> word)
	{
		++m[word];
	}
	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
	{
		cout << (*iter).first << "-" << (*iter).second << endl;
	}



	system("pause");
	return 0;
}