#include <stdio.h>
#include <stdlib.h>
void main()
{
	// 3
	int a = 7 / 2;
	printf("%d\n", a);

	//2.000000
	float b = 7 / 3; 
	printf("%f\n", b);

	//2.333333
	float c = 7 / 3.0; 
	printf("%f\n", c);

	//printf不会进行数据的类型转换, 去掉int  和float就不对
	printf("%d %f\n", (int)10.3, (float)10);
	
	//不会自动将数据的类型进行转换 
	printf("%d %f\n",  10.3, 10);
	 
}