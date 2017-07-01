#include <iostream>
#include <boost/regex.hpp>
#include <string>
#include <vector>
using namespace std;
using namespace boost;

//匹配邮箱---网页爬虫
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
	boost::regex reg4("[^13579]");  //^取补集
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
	//分割字符串
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
	当此字符紧随任何其他限定符（*、+、?、{n}、{n,}、{n,m}）之后时，匹配模式是“非贪心的”。
	“非贪心的”模式匹配搜索到的、尽可能短的字符串，而默认的“贪心的”模式匹配搜索到的、尽可能长的字符串。
	例如，在字符串“oooo”中，“o+?”只匹配单个“o”，而“o+”匹配所有“o”。
	*/
	boost::regex reg("(.*?)(\\d{2})");
	//+  *默认是贪婪匹配，即匹配最后一个符合条件的
	//加上?设置为非贪婪的重复
	boost::cmatch m;//匹配的文本不是string类型
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
	//"$1$3", 表示替换文本为第一个和第三个子表达式
	s = boost::regex_replace(s, reg, "$1$3");
	cout << s;

	/*
	//本地化
	locale::global(locale("English"));
	string str = "chengzhi123  jiayu213";
	string str2 = "_____";
	boost::regex expr("\\d");
	//根据正则表达式将str中匹配的部分替换为str2
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
		//把迭代器 it 设置为 m[0].second。match_results[0] 返回对匹配整个正则表达式的子匹配的引用
		//因此我们可以确认这个匹配的结束点就是下次运行regex_search的起始点
		it_begin = m[0].second;
	}
	if (new_counter != delete_counter)    
		std::cout << "Leak detected!\n";  
	else    
		std::cout << "Seems ok...\n";




	 

	/*
	//本地化
	locale::global(locale("English"));
	string str = "china5english345dfgdsg";
	boost::regex expr("(\\w+)\\d(\\w+)");
	boost::smatch what;
	//查找匹配正则表达式的子序列
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
	//本地化
	locale::global(locale("English"));
	string str = "123Hello 12 Hello";
	             // 3个数字 一个单词 一个任意字符 2个数字或者N/A 一个空格 重复匹配第一个单词
	boost::regex expr("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
	//判断str是否匹配正则表达式
	//匹配所有输入
	cout << boost::regex_match(str, expr) << endl;
	
	 

	cin.get();
	return 0;
}