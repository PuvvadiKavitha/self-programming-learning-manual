#include <stdio.h>
#include <stdlib.h>

/**
 * @synopsis  binary_search_1 
 *
 * @param array
 * @param length
 * @param key
 *
 * @return   
 * Note : Ordinary method.
 */
int *binary_search_1(int *array, int length, int key) {
  int low = 0;
  int mid = 0;
  int high = length - 1;

  while (low <= high) {
    mid = (high + low) / 2;

	if (key < array[mid])
		high = mid - 1;
	else if (key > array[mid])
		low = mid + 1;
	else 
		return array + mid;
  }

  return NULL;
}



/**
 * @synopsis  binary_search_2 
 *
 * @param array
 * @param length
 * @param key
 *
 * @return   
 * Note: Optimization，use ponit and >> to imporve efficiency.
 */
int *binary_search_2(int *array, int length, int key) {
  int *low = array;
  int *mid = NULL;
  int *high = array + length - 1;

  while (low <= high) {
    mid = low + ((high - low) >> 1);
	
	if (key < *mid)
		high = mid - 1;
	else if (key > *mid)
		low = mid + 1;
	else 
		return mid;
  }

  return NULL;
}


/**
 * @synopsis  binary_search_3 
 *
 * @param array
 * @param low
 * @param high
 * @param key
 *
 * @return   
 *
 * Note: Ordinary recursive method.
 */
int *binary_search_3(int *array, int low, int high, int key) {
  if (low > high) 
	  return NULL;
  
  int mid = (high + low) / 2;
  
  if (key < array[mid])
	  return binary_search_3(array, low, mid - 1, key);
  else if (key > array[mid])
	  return binary_search_3(array, mid + 1, high, key);
  else
	  return array + mid;
}


/**
 * @synopsis  binary_search_4 
 *
 * @param array
 * @param low
 * @param high
 * @param key
 *
 * @return   
 *
 * Note: Optimizing recursive method，use point and >> to imporve efficiency.
 */
int *binary_search_4(int *array, int *low, int *high, int key) {
  if (low > high) 
	  return NULL;
  
  int *mid = low + ((high - low) >> 1);
  
  if (key < *mid)
	  return binary_search_4(array, low, mid - 1, key);
  else if (key > *mid)
	  return binary_search_4(array, mid + 1, high, key);
  else
	  return mid;
}




int main(int argc, char **argv)
{
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int key = atoi(argv[1]);

  int *find1 = binary_search_1(a, 10, key);
  int *find2 = binary_search_2(a, 10, key);
  int *find3 = binary_search_3(a, 0, 10, key);
  int *find4 = binary_search_4(a, a, a + 10, key);
  
  printf("%d\n", *find1);
  printf("%d\n", *find2);
  printf("%d\n", *find3);
  printf("%d\n", *find4);
  return 0;
}
