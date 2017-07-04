#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	FILE* fp_in = NULL;
	FILE* fp_out = NULL;

	fp_in = fopen("1.txt", "r+");
	fp_out = fopen("1_back.txt", "w+");

	if (NULL == fp_in || NULL == fp_out)
	{
		
		printf("file open failed\n");
		exit(1);
	}	
	char ch = 0;
	while ((ch = fgetc(fp_in)) != EOF)
	{
		fputc(ch, fp_out);

	}

	fclose(fp_in);
	fclose(fp_out);




	return 0;
}
