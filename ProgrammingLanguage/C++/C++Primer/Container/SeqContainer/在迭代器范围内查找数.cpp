#include <iostream>
#include <vector>
using namespace std;

bool Fun(vector<int>::iterator begin, vector<int>::iterator end, int num)
{//���㷨��vector�в���num���ҵ�����true�����򷵻�false
	while (begin != end)
	{
		if (num == *begin)
		{
			return true;
		}
		begin++;
	}
	return false;
}

vector<int>::iterator Fun_2(vector<int>::iterator begin, vector<int>::iterator end, int num)
{//���㷨��vector�в���num���ҵ�����ָ��num��begin�����������򷵻�end������
	while (begin != end)
	{
		if (num == *begin)
		{
			break;
		}
		begin++;
	}
	return begin;
}

template<typename T1, typename T2>
T1 Fun_3(T1 begin, T1 end, T2 val)
{//���������ú���ģ��������begin��end֮�����num, T1�������������, T2����Ҫ���ҵ���������
//�ҵ�����ָ��������ĵ�����, û�ҵ�����end������
	while (begin != end)

	{
		if (*begin == val)
		{
			break;
		}
		begin++;
	}
	return begin;
}


int main32sadfsd()
{
	int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ivec(ia, ia + 8);
	vector<int>::iterator iter_begin = ivec.begin();
	vector<int>::iterator iter_end = ivec.end();
	cout << Fun(iter_begin, iter_end, 4) << endl; 
	cout << *Fun_2(iter_begin, iter_end, 4) << endl;
	cout << *Fun_3(iter_begin, iter_end, 4) << endl;
	system("pause");
	return 0;
}
