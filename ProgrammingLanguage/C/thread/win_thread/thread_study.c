#include <stdio.h>

// Windows thread header file.
#include <process.h>
#include <windows.h>

void run(void *p) {
	int *px = (int *)p;/
	char str[100];
	sprintf(str, "thread %d start", *px);
	MessageBoxA(0, str, "Thread", 0);
}

void main() {
	for (int i = 0; i < 5; i++) {
		// Start thread.
		_beginthread(run, 0, &i);
		Sleep(1000);
	}
}