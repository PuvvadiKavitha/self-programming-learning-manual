#include <stdio.h>
#include <stdlib.h>



int NumberOfSetBits(int i)
{
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}


unsigned int bit_count (unsigned int value) {
	unsigned int count = 0;
	while (value > 0) {           // until all bits are zero
		if ((value & 1) == 1)     // check lower bit
			count++;
		value >>= 1;              // shift bits, removing lower bit
	}
	return count;
}



int main(void)
{
	printf("7 bit count: %u\n", bit_count(7));
	printf("7 bit count: %d\n", NumberOfSetBits(7));
	return 0;
}
