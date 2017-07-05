#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef char data_t;

/*my stack*/
typedef struct my_stack {
	data_t* pdata;
	int top;
	int length;
}Stack;


/*Init stack*/
void init_stack(Stack* pstack, int length) {
	assert(length > 0);
	pstack->pdata = (data_t*)malloc(length * sizeof(data_t));
	assert(pstack->pdata != NULL);

	pstack->top = -1;
	pstack->length = length;
}

/*Free stack*/
void free_stack(Stack* pstack) {
	assert(pstack != NULL);
	assert(pstack->pdata != NULL);

	free(pstack->pdata);
	pstack->pdata = NULL;
}

/*Push data*/
void push(Stack* pstack, data_t data) {
	assert(pstack != NULL);
	assert(pstack->pdata != NULL);

	pstack->pdata[++(pstack->top)] = data;
}

/*Pop data*/
void pop(Stack* pstack, data_t* pdata) {
	assert(pstack != NULL);
	assert(pstack->pdata != NULL);
	assert(pdata != NULL);
	
	*pdata = pstack->pdata[(pstack->top)--];
}

/*Is Empty*/
int isEmpty(Stack stack) {
	return -1 == stack.top ? 1 : 0;
}

/*while*/
size_t my_strlen_1(const char* str) {

	assert(str != NULL);

	size_t length = 0;

	while (*str++) {
		length++;
	}

	return length;
}

/*recursive*/
size_t my_strlen_2(const char* str) {
	
	if ('\0' == *str) {
		return 0;
	} else {
		return my_strlen_2(++str) + 1;
	}

}

/*recursive*/
size_t my_strlen_8(const char* str) {

	static int length = 0;

	if ('\0' == *str) {
		return 0;
	} else {
		length++;
		my_strlen_8(++str);
	}
	return length;	
}

/*do while*/
size_t my_strlen_3(const char* str) {
	
	assert(str != NULL);

	size_t length = 0;

	do {
		length++;
	} while (*str++);

	return length - 1;
}

/*for*/
size_t my_strlen_4(const char* str) {
	
	assert(str != NULL);
	
	size_t length = 0;
	
	for (; *str; str++) {
		length++;
	}

	return length;

}

/*goto*/
size_t my_strlen_5(const char* str) {
	
	assert(str != NULL);

	size_t length = 0;

loop:
	if (*str++ != '\0') {
		length++;

		goto loop;
	}
	
	return length;
}

/*Loop and stack, acc the length after return*/
size_t my_strlen_6(const char* str) {
	assert(str != NULL);

	/*Function Stack*/
	Stack my_stack;
	init_stack(&my_stack, 50);
	size_t length = 0;

loop:
	if (*str++) {
		push(&my_stack, 1);
		goto loop;
	}

	data_t temp = 0;
	while (!isEmpty(my_stack)) {
		pop(&my_stack, &temp);
		length += temp;
	}

	return length;
}


/*Loop and stack, acc the length before return*/
size_t my_strlen_7(const char* str) {
	assert(str != NULL);

	Stack my_stack;
	init_stack(&my_stack, 50);
	size_t length = 0;
	data_t temp = 0;

loop:
	if (*str++) {
		
		push(&my_stack, 1);
		
		while (!isEmpty(my_stack)) {
			pop(&my_stack, &temp);
		}
		
		length += temp;
	
		goto loop;
	}

	return length;
}

/*
int main_test_stack() {
	Stack my_stack;
	int length = 2;

	init_stack(&my_stack, length);

	push(&my_stack, 1);
	push(&my_stack, 2);
	
	data_t ret_value = 0;

	pop(&my_stack, &ret_value);
	printf("%d\n", ret_value);

	
	pop(&my_stack, &ret_value);
	printf("%d\n", ret_value);

	free_stack(&my_stack);
	return 0;
}
*/


int main1() {
	const char* str = "Hello World!";
	printf("   C strlen :%s length = %lu\n", str, strlen(str));
	printf("my_strlen_1 :%s length = %lu\n", str, my_strlen_1(str));
	printf("my_strlen_2 :%s length = %lu\n", str, my_strlen_2(str));
	printf("my_strlen_3 :%s length = %lu\n", str, my_strlen_3(str));
	printf("my_strlen_4 :%s length = %lu\n", str, my_strlen_4(str));
	printf("my_strlen_5 :%s length = %lu\n", str, my_strlen_5(str));
	printf("my_strlen_6 :%s length = %lu\n", str, my_strlen_6(str));
	printf("my_strlen_7 :%s length = %lu\n", str, my_strlen_7(str));
	printf("my_strlen_8 :%s length = %lu\n", str, my_strlen_8(str));
	return 0;
}

/*Test main*/
int main() {
	size_t (*fun_array[])(const char*) = {strlen, my_strlen_1, my_strlen_2, my_strlen_3, my_strlen_4, my_strlen_5, my_strlen_6, my_strlen_7, my_strlen_8};
	
	char* pstring = "Hello World!";
	size_t (**pfun)(const char*) = NULL;

	for (int i = 0; i < 9; i++) {
		pfun = fun_array + i;
		printf("Function %d : %s length = %lu\n", i + 1, pstring, (*pfun)(pstring));
	} 
	return 0;
}




