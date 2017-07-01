#include <iostream>
#include <boost/regex.hpp>
#include <string>
#include <vector>
using namespace std;
using namespace boost;

//ƥ������---��ҳ����
int mainsadfsdfsa()
{
	boost::regex reg("\\w+@\\w+(\.\\w+)+");
	string s = "872785786@qq.com";
	cout << boost::regex_match(s, reg) << endl; 

	cin.get();
	return 0;
}



int main78567865787()
{ 
	boost::regex reg4("[^13579]");  //^ȡ����
	std::string s = "0123456789";  
	boost::sregex_iterator it(s.begin(), s.end(), reg4); 
	boost::sregex_iterator end;  
	while (it != end)     
		std::cout << *it++; 
	cin.get();
	return 0;

}




int main563465()
{
	boost::regex reg("/");
	string s = "Split/Values/Separated/By/Slashes";
	vector<string> vec;
	//�ָ��ַ���
	boost::sregex_token_iterator it_begin(s.begin(), s.end(), reg, -1);
	boost::sregex_token_iterator it_end;
	while (it_begin != it_end)
	{
		vec.push_back(*it_begin++);
	}

	for_each(vec.begin(), vec.end(), [](string str)
	{
		cout << str.c_str() << " ";
	});




	cin.get();
	return 0;

}






class regex_callback
{
public:
	int sum;
	regex_callback() : sum(0)
	{

	}

	template<typename T> 
	void operator()(const T& what)
	{
		this->sum += atoi(what[1].str().c_str());
	}
	int getSum() const
	{
		return this->sum;
	}



protected:
private:
};


int main4323523()
{
	boost::regex reg("(\\d+),?");
	string s = "1,1,2,3,5,8,13,21";
	boost::sregex_iterator it_begin(s.begin(), s.end(), reg);
	boost::sregex_iterator it_end;
	regex_callback c;
	int sum = for_each(it_begin, it_end, c).getSum();
	 
	cout << sum << endl;



	cin.get();
	return 0;
}



int main231ertewt()
{
	/*
	�����ַ������κ������޶�����*��+��?��{n}��{n,}��{n,m}��֮��ʱ��ƥ��ģʽ�ǡ���̰�ĵġ���
	����̰�ĵġ�ģʽƥ���������ġ������̵ܶ��ַ�������Ĭ�ϵġ�̰�ĵġ�ģʽƥ���������ġ������ܳ����ַ�����
	���磬���ַ�����oooo���У���o+?��ֻƥ�䵥����o��������o+��ƥ�����С�o����
	*/
	boost::regex reg("(.*?)(\\d{2})");
	//+  *Ĭ����̰��ƥ�䣬��ƥ�����һ������������
	//����?����Ϊ��̰�����ظ�
	boost::cmatch m;//ƥ����ı�����string����
	const char* text = "Note that I'm 31 years old, not 32";
	if (boost::regex_search(text, m, reg))
	{
		if (m[1].matched)
		{
			cout << "(.*)matched:" << m[1].str() << endl;
		} 
		if (m[2].matched)
		{
			cout << "age:" << m[2] << endl;
		}
	}

	cin.get();
	return 0;
}


 
int mainadsadfsa()
{

// 	boost::regex reg("(Colo)(u)(r)", boost::regex::icase | boost::regex::perl);
// 	std::string s = "Colour, colours, color, colourize";
// 	s = boost::regex_replace(s, reg, "$1$3");
// 	std::cout << s;


	boost::regex reg("(Colo)(u)(r)", boost::regex::icase | boost::regex::perl);
	string s = "Colour, colours, color, colourize";
	//"$1$3", ��ʾ�滻�ı�Ϊ��һ���͵������ӱ��ʽ
	s = boost::regex_replace(s, reg, "$1$3");
	cout << s;

	/*
	//���ػ�
	locale::global(locale("English"));
	string str = "chengzhi123  jiayu213";
	string str2 = "_____";
	boost::regex expr("\\d");
	//����������ʽ��str��ƥ��Ĳ����滻Ϊstr2
	cout << boost::regex_replace(str, expr, str2) << endl; 
	*/

	cin.get();
	return 0;
}

int main75743564()
{
	boost::regex reg("(new)|(delete)");
	boost::smatch m;
	string s = "Calls to new must be followed by delete.Calling simply new results in a leak";
	/*
	if (regex_search(s, m, reg))
	{
		if (m[1].matched)
		{
			cout << "The expression (new) matched!" << endl;
		}
		if (m[2].matched)
		{
			cout << "The expression (delete) matched!" << endl;
		}
	}*/
	int new_counter = 0;
	int delete_counter = 0;
	string::const_iterator it_begin = s.begin();
	string::const_iterator it_end = s.end();
	while (regex_search(it_begin, it_end, m, reg))
	{
		m[1].matched ? ++new_counter : ++delete_counter;
		//�ѵ����� it ����Ϊ m[0].second��match_results[0] ���ض�ƥ������������ʽ����ƥ�������
		//������ǿ���ȷ�����ƥ��Ľ���������´�����regex_search����ʼ��
		it_begin = m[0].second;
	}
	if (new_counter != delete_counter)    
		std::cout << "Leak detected!\n";  
	else    
		std::cout << "Seems ok...\n";




	 

	/*
	//���ػ�
	locale::global(locale("English"));
	string str = "china5english345dfgdsg";
	boost::regex expr("(\\w+)\\d(\\w+)");
	boost::smatch what;
	//����ƥ��������ʽ��������
	if (boost::regex_search(str, what, expr))
	{
		cout << what[0] << endl;
		cout << what[1] << endl;
		cout << what[2] << endl;
	}
	else
	{
		cout << "fail" << endl;
	} 

	*/
	cin.get();
	return 0;
}


int mainwertqwwq()
{
	//���ػ�
	locale::global(locale("English"));
	string str = "123Hello 12 Hello";
	             // 3������ һ������ һ�������ַ� 2�����ֻ���N/A һ���ո� �ظ�ƥ���һ������
	boost::regex expr("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
	//�ж�str�Ƿ�ƥ��������ʽ
	//ƥ����������
	cout << boost::regex_match(str, expr) << endl;
	
	 

	cin.get();
	return 0;
}