#include <stdio.h>

void main() {
	int num = (1, 2, 3, 2 + 6, 3 + 7); 
	
	// 10
	printf("%d\n", num); 
	// 逗号表达式用于顺序求值, 值为最后一个表达式的值, 运算符的方向是从左向右
	// 不用于计算的时候，起到间隔符号的作用，让语句连在一起

	/*
	 * Comma expression user for order evaluation, 
	 * the expression evaluations from left to right, 
	 * and the final value is the value of the last expression.
	 */
	int num1 = (num1 = 3 * 5, num1 * 4, num1 + 5); //20
	printf("%d\n", num1);
}