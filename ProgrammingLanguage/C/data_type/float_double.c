#include <stdio.h>

void main() {
	// 4, 8
	printf("%d %d\n", sizeof(float), sizeof(double));
	float f = 1.012;
	double db = 2.0112;
	printf("%f %f\n", f, db);
}