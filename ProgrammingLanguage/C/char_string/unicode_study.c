#include <stdio.h>
#include <stdlib.h> 

void main() {
	// char only can not store chinese.
	char ch = '我';
	printf("%c\n", ch);

	char str[10] = "我爱你";
	// String can show chinese.
	//printf("%c %c\n", str[0], str[1]);
	printf("%s\n", str);
}