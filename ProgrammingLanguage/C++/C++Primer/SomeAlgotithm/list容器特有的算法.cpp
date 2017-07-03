#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <list>
using namespace std;
static void PrintList(list<int> ilist)
{
	for (list<int>::iterator it = ilist.begin(); it != ilist.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool compare(const int &a, const int &b)
{
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

bool GT2(const int &a)
{
	return a <= 2;
}



int main()
{
	int a[] = { 1, 1, 1, 1, 1, 1,12, 0, 6, 45, 5, 522 };
	int b[] = { 6, 7, 8, 9, 10 };
	list<int> ilistA(a, a + 12);
	list<int> ilistB(b, b + 5);
	PrintList(ilistA);
	PrintList(ilistB);
// 	ilistA.merge(ilistB);
// 	PrintList(ilistA);
// 	PrintList(ilistB);

// 	ilistA.merge(ilistB, compare);
// 	PrintList(ilistA);
// 	PrintList(ilistB);

// 	ilistA.remove(1);
// 	PrintList(ilistA);
// 
// 	ilistA.remove_if(GT2);
// 	PrintList(ilistA);
// 
// 	ilistA.sort();
// 	PrintList(ilistA);


// 	ilistA.unique();
// 	PrintList(ilistA);

// 	ilistA.unique(GT2);
// 	PrintList(ilistA);


// 	ilistA.splice(ilistA.begin(), ilistB);
// 	PrintList(ilistA);
// 	PrintList(ilistB);

// 	ilistA.splice(ilistA.begin(), ilistB, ilistB.begin());
// 	PrintList(ilistA);
// 	PrintList(ilistB);

// 	ilistA.splice(ilistA.begin(), ilistB, ilistB.begin(), ilistB.end());
// 	PrintList(ilistA);
// 	PrintList(ilistB);
	 

	system("pause");
	return 0;
}
