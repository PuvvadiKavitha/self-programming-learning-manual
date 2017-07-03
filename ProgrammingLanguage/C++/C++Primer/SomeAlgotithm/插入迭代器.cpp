#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
#include <iterator>
#include <list>
using namespace std;
int main54654ljlkjl()
{
	
	//fill_n(back_inserter(ivec), 10, 1);
	int a[] = { 1, 2, 3, 4, 5 , 1, 1, 1};
	list<int> ilist(a, a + 8);
	
	//vector<int> ivec(ilist.begin(), ilist.end());
	vector<int> ivec;
	//copy(ilist.begin(), ilist.end(), back_inserter(ivec));
	
	//replace(ivec.begin(), ivec.end(), 1, 111);
	replace_copy(ilist.begin(), ilist.end(), back_inserter(ivec), 1, 111);
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++)
	{
		cout << *iter << " ";
	}


	system("pause");
	return 0;
}