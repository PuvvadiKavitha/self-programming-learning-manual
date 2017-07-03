#include <iostream>
#include <algorithm>
#include <numeric> 
#include <string>
#include <vector>
using namespace std;
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool GT6(const string &s)
{
	return s.size() >= 6;
}


int main231dsfgdfg()
{ 
	string word;
	vector<string> ivec;

	while (cin >> word)
	{
		ivec.push_back(word);
	}
	sort(ivec.begin(), ivec.end());//排序
	vector<string>::iterator end_unique = unique(ivec.begin(), ivec.end());//找出重复单词
	ivec.erase(end_unique, ivec.end());//删除重复单词
	stable_sort(ivec.begin(), ivec.end(), isShorter);//按单词长度排序
	cout << endl;
	for (vector<string>::iterator iter_begin = ivec.begin(); iter_begin != ivec.end(); iter_begin++)
	{
		cout << *iter_begin << " ";//输出排序后的单词
	}
	vector<string>::size_type wc = count_if(ivec.begin(), ivec.end(), GT6);//统计长度大于6的单词数
	cout << wc << " word" << "6 characters or longer" << endl;
	system("pause");
	return 0;
}
