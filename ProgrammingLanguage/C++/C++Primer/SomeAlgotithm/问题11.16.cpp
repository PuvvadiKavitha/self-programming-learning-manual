#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
using namespace std;
int main231sgsdfg()
{
	string file_name;
	cout << "please input file name:";
	cin >> file_name;
	ifstream in(file_name.c_str());
	if (!in)
	{
		cout << "Open file fail!" << endl;
		system("pause");
		return -1;
	}
	istream_iterator<string> in_iter_begin(in);
	istream_iterator<string> in_iter_end;

	ostream_iterator<string> out_iter(cout, " ");

	copy(in_iter_begin, in_iter_end, out_iter);

	in.close();
	system("pause");
	return 0;
}
