#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <vector>


/*
 * Study wite:
 * https://deerchao.net/tutorials/regex/regex.htm
 * http://www.runoob.com/regexp/regexp-tutorial.html
 */

int main1() {
  boost::regex reg("[0-9]+");
  std::string str = "123456";
  std::cout << boost::regex_match(str, reg) << std::endl;
  return 0;
}


int main2() {
  boost::regex reg("^[0-9]+abc$");
  std::string str = "123abc";
  std::cout << boost::regex_match(str, reg) << std::endl;
  return 0;
}




int main3() {
  boost::regex reg("\\w+@\\w+(.\\w+)+");
  std::string s = "872785786@qq.com";
  std::cout << boost::regex_match(s, reg) << std::endl; 

  return 0;
}




int main4() { 
  boost::regex reg("[^13579]"); 
  std::string s = "0123456789";  
  boost::sregex_iterator begin(s.begin(), s.end(), reg); 
  boost::sregex_iterator end;  
  while (begin != end)     
    std::cout << *begin++; 

  std::cout << std::endl;
  return 0;
}





int main5() {
	boost::regex reg("/");
	std::string s = "Split/Values/Separated/By/Slashes";
	std::vector<std::string> vec;
	
	// Using reg to split string.
	boost::sregex_token_iterator it_begin(s.begin(), s.end(), reg, -1);
	boost::sregex_token_iterator it_end;
	while (it_begin != it_end)
		vec.push_back(*it_begin++);
	
	std::for_each(vec.begin(), vec.end(), [](std::string str)
	{
		std::cout << str.c_str() << " ";
	});

	std::cout << std::endl;
	return 0;
}







class regex_callback {
public:
	int sum;
	regex_callback() : sum(0) { }

	template<typename T> 
	void operator()(const T& what) {
		this->sum += atoi(what[1].str().c_str());
	}

	int getSum() const {
		return this->sum;
	}

};


int main6() {
  boost::regex reg("(\\d+),?");
  std::string s = "1,1,2,3,5,8,13,21";
  boost::sregex_iterator it_begin(s.begin(), s.end(), reg);
  boost::sregex_iterator it_end;
	
  regex_callback c;
  // Get sum
  int sum = std::for_each(it_begin, it_end, c).getSum();
	 
  std::cout << sum << std::endl;

  return 0;
}




int main7() {
	boost::regex reg("(.*?)(\\d{2})");
	boost::cmatch m;
	const char* text = "Note that I'm 31 years old, not 32";
	// Search result
	if (boost::regex_search(text, m, reg)) {
		if (m[1].matched) 
			std::cout << "(.*)matched:" << m[1].str() << std::endl;
		 
		if (m[2].matched) 
			std::cout << "age:" << m[2] << std::endl;
	}

	return 0;
}


 

int main8() {
	boost::regex reg("(Colo)(u)(r)", boost::regex::icase | boost::regex::perl);
	std::string s = "Colour, colours, color, colourize";
	// Replace 1th and 3th string.
	s = boost::regex_replace(s, reg, "$1$3");
	std::cout << s;

	return 0;
}


int main9() {
	boost::regex reg("(new)|(delete)");
	boost::smatch m;
	std::string s = "Calls to new must be followed by delete.Calling simply new results in a leak";

	int new_counter = 0;
	int delete_counter = 0;
	
	std::string::const_iterator it_begin = s.begin();
	std::string::const_iterator it_end = s.end();
	
	while (regex_search(it_begin, it_end, m, reg)) {
		m[1].matched ? ++new_counter : ++delete_counter;
		it_begin = m[0].second;
	}

	if (new_counter != delete_counter)    
		std::cout << "Leak detected!\n";  
	else    
		std::cout << "Seems ok...\n";

	return 0;
}


int main() {
	//std::locale::global(std::locale("English"));
	std::string str = "china5english345dfgdsg";
	boost::regex expr("(\\w+)\\d(\\w+)");
	boost::smatch what;
	// Search sub match string.
	if (boost::regex_search(str, what, expr)) {
		std::cout << what[0] << std::endl;
		std::cout << what[1] << std::endl;
		std::cout << what[2] << std::endl;
	} else {
		std::cout << "fail" << std::endl;
	} 

	return 0;
}


int main11() {
	//std::locale::global(std::locale("English"));
	std::string str = "123Hello 12 Hello";
	
	boost::regex expr("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
	
	std::cout << boost::regex_match(str, expr) << std::endl;
	
	return 0;
}
