#include <iostream> 
#include <string>
using namespace std;

template <typename T>
class com
{
public:
	com(T a, T b) : a(a), b(b)
	{

	}
	T add()
	{
		return this->a + this->b;
	}
protected:
private:
	T a;
	T b;
};
 


int main1()
{
	com<int> c1(2, 3);
	cout << c1.add() << endl;

	com<double> c2(2.2, 3.3);
	cout << c2.add() << endl;

	string str1("Hello");
	string str2("world");
	com<string> c3(str1, str2);
	cout << c3.add() << endl;




	system("pause");
	return 0;
}