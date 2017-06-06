#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This function convert a interage number to a binary string,
 * you need to pass a interage value to this function, then this
 * function will return a char* pointer to a binary string .
 * Note that: When you don`t need to use the return value, you 
 * need to free this pointer .
 * For example: 
 *	char *str = NumToBinStr(10);
 * 	...
 * 	//you don`t use above str, you need to free .
 * 	free(str)
 */
static char* NumToBinStr(const int num)
{
	int num_length = 0;
	// Get num length .
	for (int i = num; i > 0; i /= 2)
		num_length++;

	// Malloc memory for storage binary string .
	char* bin_str = (char*)malloc(sizeof(char) * num_length);

	if (NULL == bin_str) 
	{
		printf("Malloc string memory failed!\n");
		return NULL;
	} 
	else 
	{
		memset(bin_str, 0, sizeof(bin_str));
		char m = '0';
		int bin_str_index = 0;
		for (int i = num; i > 0; i /= 2)
		{
			// Get remainder .
			m = i % 2 + '0';
			//Reverse storage binary char to bin_str array .
			bin_str[num_length - bin_str_index - 1] = m;
			bin_str_index++;
		}

		bin_str[num_length] = '\0';

		return bin_str;
	}
}



int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Usage：./a.out 10\n");
		return -1;
	}

	int N = atoi(argv[1]);
	char *bin_str = NumToBinStr(N);

	if (bin_str != NULL) 
	{
		printf("%d binary string = %s\n", N, bin_str);
		free(bin_str);
	}
	else
	{
		printf("NumToBinStr return NULL\n");
	}

	return 0;
}








