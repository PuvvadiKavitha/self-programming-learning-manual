#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <process.h>
#include <windows.h>
#define SIZE 1000

int flag = 0;
int *addrFind = NULL;

struct MyStruct {
	int *pfindstart;//要查找的首地址
	int length;//前进的元素 限定长度
	int *pflag;//用于通信
	int **addr;//传递找到的数据的地址
	int num;//要查找的数据
	int bh;//线程的编号
};

void find(void *p) {
	struct MyStruct *pstruct = (struct MyStruct *)p;
	
	// Start search 100 array entry.
	for (int *px = pstruct->pfindstart; px < pstruct->pfindstart + SIZE / 10; px++) {
		Sleep(1);
		
		// Other thread has search.
		if (*(pstruct->pflag)!=0) {
			printf("属下%d无能，其他线程已经找到\n", pstruct->bh);
			return;
		}

		// This thread has search.
		if (*px == pstruct->num) {
			printf("第%d个线程找到,地址为%p,%d\n", pstruct->bh, px, *px);
			*(pstruct->pflag) = 1;
			*(pstruct->addr) = px;
			return;
		} 
	}

	printf("第%d个线程没有找到\n", pstruct->bh); 
}

void time(void *p) {
	int i = 0;
	while (1) {
		char str[100] = {0};
		sprintf(str, "title 程序运行第%d秒", i+1);
		system(str);
		i++;
		Sleep(1000);
	}	 
}

void main() {
	// Start time thread.
	_beginthread(time, 0, NULL);
	
	int n = 0;
	printf("请输入要查找的数据:");
	scanf("%d", &n);
	int a[SIZE];
	
	for (int i = 0; i <SIZE; i++)	
		a[i] = i;
	
	struct MyStruct thearddata[10];
	for (int i = 0; i < 10; i++) {
		// Calcuate every thread search address, SIZE / 10 = 100
		thearddata[i].pfindstart = a + i * SIZE / 10; 
		thearddata[i].length = 100;
		thearddata[i].bh = i + 1;
		thearddata[i].num = n;
		thearddata[i].pflag = &flag;
		thearddata[i].addr = &addrFind;
		// Start thread with no block mode.
		_beginthread(find, 0, &thearddata[i]);
		// Malloc memory need time.
	    Sleep(1);
	}

}