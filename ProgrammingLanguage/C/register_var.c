#include <stdio.h>
//需要频繁使用的变量放在寄存器中 可以提高速度
//寄存器变量在cpu里面没有地址（c++里面有）
//vc会自动优化 gcc不会
//寄存器变量用于频繁使用的变量，提升代码速度，
//全局变量，静态变量一般不要放在寄存器，因为寄存器数量有限。
void main() {
	for (register int i = 0; i < 10; i++)
		printf("%d\n", i);
}