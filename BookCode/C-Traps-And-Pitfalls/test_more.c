#include <stdio.h>
#include <stdlib.h>

typedef void(*Fun)();
 
void F()
{

}

int main(void)
{
	int a = 2;
	int b = 2;
	int c = a-- -b;
	//  0 
	printf("%d\n", c);

	int *p = &a;
	int y = a / (*p);
	int c1 = -1;
	
	char hello[] = { 'H', 'E', 'L', 'L', 'o', '\0' };
	printf(hello);
	
	//printf('\n'); 
	// printf parameter must be a string.
	printf("\n");

	char ch = 'yes';
	// s
	putchar(ch);

	int d = 2;
	d-- > 0;
	// a must be a left value that can be modify.
	//a++ = b; 
	//printf("%d", ((a++)++) + b);

	//����ָ�������
	//(*(void(*)())0)();
	//(*(Fun)0)();

	//signal����ֵΪvoid����ָ��, ����Ϊint��void����ָ��
	//void(*signal(int, void(*)(int)))(); 
	//Fun signal(int, Fun);
	 

	return 0;
}
