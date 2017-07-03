#include <iostream>
#include <algorithm>
#include <numeric> 
#include <iterator>
#include <fstream>
using namespace std;
int main1()
{
	ifstream in;
	in.open("C:\\Users\\Administrator\\Desktop\\1.txt", ios::in);

	ofstream out;
	out.open("C:\\Users\\Administrator\\Desktop\\2.txt", ios::out);

	istream_iterator<char> in_begin(in);
	istream_iterator<char> in_end;

	ostream_iterator<char> out_begin(out, " ");

	copy(in_begin, in_end, out_begin);

	in.close();
	out.close();




	system("pause");
	return 0;
}