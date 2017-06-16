#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <process.h>
#include <windows.h>

void go(void *p) {
	int *px = (int *)p;
	int i = 0;
	while (1) {
		if (i > 1) {
			printf("%ds later，thread %d stop\n", i, *px);
			// stop thread
			_endthread();
		}

		i++;
		// Sleep 1s
		Sleep(1000);
	}
}


void time(void *p) {
	int i = 0;
	while (1) {
		char str[100] = { 0 };
		sprintf(str, "title current time %ds", i);
		// Exec str command.
		system(str);
		i++;
		Sleep(1000);

	} 
}

void main() {
	// Start time thread.
	_beginthread(time, 0, NULL);
	for (int i = 0; i < 5; i++) {
		HANDLE hd = _beginthread(go, 0, &i);
		// Start thread with block mode.
		WaitForSingleObject(hd, INFINITE);
		Sleep(1000);
	}
}