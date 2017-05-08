#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int N = atoi(argv[1]);
	printf("N = %d\n", N);

	int length = 0;
	for (int i = N; i > 0; i /= 2)
		length++;
	//printf("length = %d\n", length);

	char* strings = (char*)malloc(sizeof(char) * length);
	if (NULL == strings)
	{
		printf("malloc failed!!!\n");
		return -1;
	}

	char m = '0';
	int strings_index = 0;
	for (int i = N; i > 0; i /= 2)
	{
		m = i % 2 + '0';
		//printf("m = %d\n", m);
		strings[length - strings_index - 1] = m;
		strings_index++;
	}

	strings[length] = '\0';

	printf("N binary strings = %s\n", strings);

	return 0;
}

