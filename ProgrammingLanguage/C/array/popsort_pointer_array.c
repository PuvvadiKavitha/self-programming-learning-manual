#include <stdio.h>
#include <string.h>

void main() {
	char *p[4] = { "calc", "notepad", "tasklist", "write" };
	
	for (int i = 0; i < 4; i++)
		printf("%c, %s\n", *p[i], p[i]);
	
	printf("\n");
 
 	// Pop sort
	for (int i = 0; i < 4-1; i++) {
		for (int j = 0; j < 4 - 1 - i; j++) {
			if (strcmp(p[j], p[j+1]) < 0) {
				char *px;
				px = p[j];
				p[j] = p[j + 1];
				p[j + 1] = px;
			} 
		}
	}

	for (int i = 0; i < 4; i++)	
		printf("%c, %s\n", *p[i], p[i]);

}