/**
* @file Ex_1_1_13.c
* @synopsis  
* @author cheng-zhi, chengzhihjy@gmail.com
* @version 1.0
* @date 2017-05-13
*/
#include <stdio.h>
#include <stdlib.h>

/**
* @synopsis  ShowArrayTranspose 
*
* @param row
* @param col
* @param array[row][col]
*/
static void ShowArrayTranspose(int row, int col, int array[row][col])
{
	int t_row = col;
	int t_col = row;

	// Malloc pointer array .
	int** t_array = (int **)malloc(sizeof(int *) * t_row);
	if (NULL == t_array)
	{
		printf("Malloc T array failed!\n");
		return ;
	}
	
	// Malloc each array memory .
	for (int i = 0; i < t_row; i++)
	{
		t_array[i] = (int *)calloc(sizeof(int) * t_col, sizeof(int));
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			// Start Transpose...
			t_array[j][i] = array[i][j];
		}
	}
	
	//Show origin array .
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d\t", array[i][j]);
		}
		
		putchar('\n');
	}

	// Show T array .
	puts("T:");
	for (int i = 0; i < t_row; i++)
	{
		for (int j = 0; j < t_col; j++)
		{
			printf("%d\t", t_array[i][j]);
		}

		putchar('\n');
	}

	free(t_array[0]);
	free(t_array);
}


/**
* @synopsis  main 
*
* @param argc
* @param argv
*
* @returns   
*/
int main(int argc, char **argv)
{
	int a[3][3] = { 1, 1, 1, 1, 0, 0, 0, 0, 1};
	ShowArrayTranspose(3, 3, a);
	return 0;
}

