/**
 * @file Ex_1_1_22.c
 * @synopsis  Ex_1_1_22.c
 * @author cheng-zhi, chengzhihjy@gmail.com
 * @version 1.0
 * @date 2017-05-19
 */
#include <stdio.h>
#include <stdlib.h>




/**
 * @synopsis  binary_search 
 *
 * @param a[] array that must be have sort !
 * @param low array min value
 * @param high array max value
 * @param key find value
 *
 * @return finde value index in array
 *
 * Note:
 * 	recursive binary_search
 */
static int binary_search(int a[], int low, int high, int key)
{
	if (low > high)
		return -1;
	
	// Because we need to store deep, so we must declare 'static' key word !
	static int deep = 0;


	// Show low deep .
	printf("\nlow:\t");
	for (int i = 0; i < deep; i++)
	{
		printf("\t");
	}
	
	printf("%d\n", low);
	
	// Show high deep .
	printf("high:\t");
	for (int i = 0; i < deep; i++)
	{
		printf("\t");
	}
	
	printf("%d\n", high);
	

	int mid = low + (high - low) / 2;
	
	// [low	  mid - 1] mid [mid + 1	  high]
	// 		<           =           >
	if (key > a[mid])
	{
		deep++;
		return binary_search(a, mid + 1, high, key);
	}else if (key < a[mid])
	{
		deep++;
		return binary_search(a, low, mid - 1, key);
	}else
		return mid;
	
}





/**
 * @synopsis  main 
 *
 * @return  
 *
 * Compile run:
 * 	gcc Ex_1_1_22.c 
 * 	./a.out
 */
int main(void)
{

	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	printf("a[]: ");
	for (int i = 0; i < 16; i++)
		printf("%d ", a[i]);
	
	int key = a[12];
	printf("\nkey = %d\n\n", key);
	
	int key_index = binary_search(a, a[0], a[15], key);
	printf("\na[%d] = %d\n", key_index, a[key_index]);
	return 0;
}


