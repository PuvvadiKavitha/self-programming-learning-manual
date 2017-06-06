#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/**
 * @synopsis  alloc_matrix 
 *
 * @param row
 * @param col
 *
 * @return double **
 *
 * Note:
 *   if you don`t need return value, you must be call free_matrix!
 *
 */
static double **alloc_matrix(int row, int col) {
  double **t_array = (double **)malloc(sizeof(double *) * row);
  if (t_array == NULL) {
    printf("Malloc t_array failed.\n");
	return NULL;
  }
  
  for (int i = 0; i < row; i++) {
	t_array[i] = (double *)malloc(sizeof(double) * col);
    memset(t_array[i], 0, sizeof(t_array[i]));
    if (t_array[i] == NULL) {
      printf("Malloc t_array[%d] faile.\n", i);
	  return NULL;
	}
  }
  
  return t_array;
}


/**
 * @synopsis  print_matrix 
 *
 * @param row
 * @param col
 * @param xi
 *
 *   1.00	2.00
 *   3.00	4.00
 */
static void print_matrix(int row, int col, double **x) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("\t%.2f\t", x[i][j]);
	}
	putchar('\n');
  }
}

/**
 * @synopsis  free_matrix 
 *
 * @param row
 * @param x
 */
static void free_matrix(int row, double **x) {
  for (int i = 0; i < row; i++) {
	free(x[i]);
    x[i] = NULL;
  }

  free(x);
  x = NULL;
}





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

  double **mult_array = alloc_matrix(mult_row, mult_col);
 
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



/**
 * @synopsis  transpose 
 *
 * @param row
 * @param col
 * @param x[row][col]
 *
 * @return   
 *   How to T array:
 *   1 2
 *   3 4
 *   ->
 *   1 3
 *   2 4
 *
 *   => b[j][i] = a[i][j]
 */
static double **transpose(int row, int col, double x[row][col]) {
  int t_row = col;
  int t_col = row;
  
  // Alloc matrix.
  double **t_array = alloc_matrix(t_row, t_col);
  
  // T array: b[j][i] = a[i][j]
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      t_array[j][i] = x[i][j]; 
  
  return t_array;
}

/**
 * @synopsis  mult_one 
 *
 * @param row
 * @param col
 * @param x[row][col]
 * @param len
 * @param y[len]
 *
 * @return   
 *   1 2  
 *   3 4 
 *    *
 *   2 3
 *    =
 *   [1 * 2 + 2 * 3, 2 * 3 + 3 * 4]
 */
static double *mult_one(int row, int col, double x[row][col], int len, double y[len]) {

  if (col != len) {
    return NULL;
  }

  double *matrix = (double *)malloc(sizeof(double) * col);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
	  matrix[i] += x[i][j] * y[j];
	}
  }

  return matrix;
}

/**
 * @synopsis  mult_two 
 *
 * @param len
 * @param y[len]
 * @param row
 * @param col
 * @param x[row][col]
 *
 * @return   
 *   2 3
 *    *
 *   1 2 
 *   3 4
 *    =
 *   [2 * 1 + 2 * 2, 3 * 3 + 3 * 4]
 */
static double *mult_two(int len, double y[len], int row, int col, double x[row][col]) {

  if (col != len) {
    return NULL;
  }

  double *matrix = (double *)malloc(sizeof(double) * len);

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < col; j++) {
	  matrix[i] += y[i] * x[i][j];
	}
  }

  return matrix;
}

void test_mult_one() {
  double x[2][2] = { 1, 2, 3, 4 };
  double y[2] = { 2, 3 };

  double *ret = mult_one(2, 2, x, 2, y);
  for (int i = 0; i < 2; i++)
	  printf("\t%.2f\t", ret[i]);
}

void test_mult_two() {
  double x[2][2] = { 1, 2, 3, 4 };
  double y[2] = { 2, 3 };

  double *ret = mult_two(2, y, 2, 2, x);
  for (int i = 0; i < 2; i++)
	  printf("\t%.2f\t", ret[i]);
}



static void test_dot() {
  double x[3] = { 3, 2, 3 };
  double y[3] = { 3, 2, 1 };
  double sum = dot(x, 3, y, 3);
  printf("\tsum = %.3f\n", sum);
}


static void test_mult() {
  double x[2][2] = { 1, 2, 3, 4 };
  double y[2][2] = { 1, 2, 3, 4 };
 
  double** mult_array = mult(2, 2, x, 2, 2, y);
  
  print_matrix(2, 2, mult_array);

  free_matrix(2, mult_array);

}

static void test_transpose() {
  double x[2][2] = { 1, 2, 3, 4 };
  double **t = transpose(2, 2, x);

  print_matrix(2, 2, t);

  free_matrix(2, t);
}

/**
 * @synopsis  main 
 *
 * @return   
 */
int main(void)
{
  test_dot();
  putchar('\n');
  
  test_mult();
  putchar('\n');
  
  test_transpose();
  putchar('\n');
  
  test_mult_one(); 
  putchar('\n');
  
  test_mult_two(); 
  putchar('\n');
  return 0;
}


