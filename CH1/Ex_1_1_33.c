#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @synopsis  dot 
 *
 * @param x[]
 * @param xlen
 * @param y[]
 * @param ylen
 *
 * @return 
 *   向量点乘
 *   sum = x[0] * y[0] + x[1] * y[1] + x[2] * y[2] + ... + x[xlen - 1] * y[xlen - 1]
 */
static double dot(double x[], int xlen, double y[], int ylen) {
  if (xlen != ylen) {
    printf("x len must equal to y len.\n");
    return -1;
  }

  double sum = 0;
  for (int i = 0; i < xlen; i++)
    sum += x[i] * y[i];

  return sum;
}


/**
 * @synopsis  mult 
 *
 * @param xrow
 * @param xcol
 * @param x[xrow][xcol]
 * @param yrow
 * @param ycol
 * @param y[yrow][ycol]
 *
 * @return   
 *   矩阵相乘，参看定义：https://zh.wikipedia.org/wiki/%E7%9F%A9%E9%99%A3%E4%B9%98%E6%B3%95
 */
static double** mult(int xrow, int xcol, double x[xrow][xcol], int yrow, int ycol, double y[yrow][ycol]) {
  if (xcol != yrow) {
    printf("xcol must be equal to yrow.\n");
    return NULL;
  }

  int mult_row = xrow;
  int mult_col = ycol;

  // Alloc [][] memory
  double **mult_array = (double **)malloc(sizeof(double *) * mult_row);
  if (mult_array == NULL) {
    printf("Malloc ** faile.\n");
	return NULL;
  }
  
  // Alloc [i] memory
  for (int i = 0; i < mult_row; i++) {
	mult_array[i] = (double *)malloc(sizeof(double) * mult_col);
    memset(mult_array[i], 0, sizeof(mult_array[i]));
    if (mult_array[i] == NULL) {
      printf("Malloc * faile.\n");
	  return NULL;
	}
  }
  
  
  double tmp_sum = 0;
  for (int i = 0; i < xrow; i++) {
    for (int k = 0; k < ycol; k++) {
      for (int j = 0; j < xcol; j++) {
	    // mult_array[0][0] = x[0][0] * y[0][0] +
		//                    x[0][1] * y[1][0] 
	    
		// mult_array[0][1] = x[0][0] * y[0][1] +
		//                    x[0][1] * y[1][1] 
	    tmp_sum += x[i][j] * y[j][k];
	  }
	  mult_array[i][k] = tmp_sum;
	  tmp_sum = 0;
	}
  }

  return mult_array;
}



void test_dot() {
  double x[3] = { 3, 2, 3 };
  double y[3] = { 3, 2, 1 };
  double sum = dot(x, 3, y, 3);
  printf("sum = %.3f\n", sum);
}


void test_mult() {
  double x[2][2] = { 1, 2, 3, 4 };
  double y[2][2] = { 1, 2, 3, 4 };
 
  double** mult_array = mult(2, 2, x, 2, 2, y);
  for (int i = 0; i < 2; i++) {
	  for (int j = 0; j < 2; j++) {
		  printf("\t%.2f\t", mult_array[i][j]);
	  }
	  putchar('\n');
  }
}



/**
 * @synopsis  main 
 *
 * @return   
 */
int main(void)
{
  test_dot();
  test_mult();

  return 0;
}


