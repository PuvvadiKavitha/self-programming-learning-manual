#include <iostream>
#include <string> 


/*
 * C++11 will add three unicode code type: UTF-8, UTF-16, UTF-32
 * And C++11 will also add two new char type: char16_t, char32_t
 * The two new char type used as to storge UTF-16 and UTF-32.
 */

int main() {
	// Ok
	const char *s1 = "UTF-8 string";
	
	// Don't compile! 
	const char16_t *s2 = U"UTF-16 string";
	
	// Ok
	const char32_t *s3 = U"UTF-32 string";
 
	return 0;
}