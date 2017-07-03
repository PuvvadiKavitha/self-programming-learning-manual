#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <fstream>
using namespace std;

ofstream& open_file(ofstream &out, const string &file)
{
	out.close();
	out.clear();
	out.open(file.c_str());
	return out;
}

int main32d1fg()
{
 	ofstream oddFile;
 	ofstream evenFile;

	open_file(oddFile, "oddFile.dat");
	open_file(evenFile, "evenFile.dat");

	if (!oddFile || !evenFile)
	{
		cout << "file open fail!" << endl;
		system("pause");
		return -1;
	}

	istream_iterator<int> in_iter_begin(cin);
	istream_iterator<int> in_iter_end;

	ostream_iterator<int> out_odd_iter(oddFile, " ");
	ostream_iterator<int> out_even_iter(evenFile, "\n");

	while (in_iter_begin != in_iter_end)
	{
		if (*in_iter_begin % 2 != 0)
		{
			*out_odd_iter++ = *in_iter_begin++;
		}
		else
		{
			*out_even_iter++ = *in_iter_begin++;
		}
	}
	oddFile.close();
	evenFile.close();
	system("pause");
	return 0;
}
