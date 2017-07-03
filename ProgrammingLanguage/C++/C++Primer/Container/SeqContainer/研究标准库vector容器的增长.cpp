#include <iostream>
#include <vector>
using namespace std;
int main6ewt46rwt()
{
	vector<int> ivec;
	cout << "size = " << ivec.size() << " cap = " << ivec.capacity() << endl;
	//ivec.assign(5, 1);
	for (vector<int>::size_type ix = 0; ix != 24; ix++)
	{
		ivec.push_back(ix);
	} 
	cout << "size = " << ivec.size() << " cap = " << ivec.capacity() << endl;
	while (ivec.size() != ivec.capacity())
	{
		ivec.push_back(0);
	}
	ivec.push_back(1);
	cout << "size = " << ivec.size() << " cap = " << ivec.capacity() << endl;

	ivec.reserve(100);
	cout << "size = " << ivec.size() << " cap = " << ivec.capacity() << endl;

	ivec.resize(20);
	cout << "size = " << ivec.size() << " cap = " << ivec.capacity() << endl;

	system("pause");
	return 0;
}
