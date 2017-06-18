#include <stdio.h> 
#include <assert.h> 

#define myassert(x)\
if (!(x))\
	{\
	printf("myassert(%s)\nstart assert...\n", #x);\
	printf("current function name: %s，file name: %s，code line number: %d\n",\
	__FUNCTION__, __FILE__, __LINE__);\
    }

void main() {
	int num = 10;
	//myassert(num > 20);
	assert(num > 20);
}