#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 5

int main(void)
{
	int calendar[M][N];
	int(*mouthp)[N];

	int i = 0; 
	
	for (mouthp = calendar; mouthp < calendar[12]; mouthp++)
	{
		int *dayp;
		for (dayp = *mouthp; dayp < &(*mouthp)[31]; dayp++)
		{
			*dayp = i++;
			printf("%d\n", i);
		}
	}
	 
	return 0;
}
