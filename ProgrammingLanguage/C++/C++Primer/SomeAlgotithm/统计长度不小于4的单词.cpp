#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

bool isShorter_2(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool GT4(const string &s)
{
	return s.size() >= 4;
}

int main1321sfgsd()
{
	vector<string> ivec;
	string word;
	while (cin >> word)
	{
		ivec.push_back(word);
	}

	sort(ivec.begin(), ivec.end());
	vector<string>::iterator end_unique = unique(ivec.begin(), ivec.end());
	ivec.erase(end_unique, ivec.end());
	stable_sort(ivec.begin(), ivec.end(), isShorter_2);
	for (vector<string>::iterator iter_begin = ivec.begin(); iter_begin != ivec.end(); iter_begin++)
	{
		cout << *iter_begin << " ";//输出排序后的单词
	}
	vector<string>::size_type wc = count_if(ivec.begin(), ivec.end(), GT4);
	cout << endl << wc << " word" << " 4 characters or longer" << endl; 

	system("pause");
	return 0;
}
