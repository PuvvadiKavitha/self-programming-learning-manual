#include <iostream>
#include <algorithm>
#include <numeric> 
#include <string>
#include <vector>
using namespace std;
static bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

static bool GT6(const string &s)
{
	return s.size() >= 6;
}


int main21546lkj()
{
	string word;
	vector<string> ivec;

	while (cin >> word)
	{
		ivec.push_back(word);
	}
	sort(ivec.begin(), ivec.end());//����
	vector<string>::iterator end_unique = unique(ivec.begin(), ivec.end());//�ҳ��ظ�����
	ivec.erase(end_unique, ivec.end());//ɾ���ظ�����
	stable_sort(ivec.begin(), ivec.end(), isShorter);//�����ʳ�������
	cout << endl;
	for (vector<string>::iterator iter_begin = ivec.begin(); iter_begin != ivec.end(); iter_begin++)
	{
		cout << *iter_begin << " ";//��������ĵ���
	}
	vector<string>::size_type wc = 0;//ͳ�Ƴ��ȴ���6�ĵ�����
	vector<string>::iterator iter_begin = ivec.begin();
	while ((iter_begin = find_if(iter_begin, ivec.end(), GT6)) != ivec.end())
	{
		wc++;
		iter_begin++;
	}
	  
	cout << endl << wc << " word" << "6 characters or longer" << endl;
	system("pause");
	return 0;
}
