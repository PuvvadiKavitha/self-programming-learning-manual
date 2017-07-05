#include "mystring.h"


int mystrlen(const char* str) {
	if ('\0' == *str) {
		return 0;
	} else {
		return mystrlen(++str) + 1;
	}
}

char *mystrcpy(char *dest, const char *source) {
	if (dest == NULL || source == NULL)
		return NULL;
	
	char * destbak = dest;
	
	while (*source)
		*dest++ = *source++;

	*dest = '\0';
	return destbak;
}


char *mystrcat(char *source, const char *add_str) {
	if (source == NULL || add_str == NULL) {
		return NULL;
	} else {
		char *source_bak = source;
		
		while (*source)
			source++;
		
		while (*add_str)
			*source++ = *add_str++;
		
		*source = '\0';
		return source_bak;
	}
}


char *mystrchr(char *dest, char find_char) {
	if (dest == NULL)
		return NULL;
	
	char *dest_bak = dest;

	while (*dest_bak) {
		if (*dest_bak == find_char)
			return dest_bak;
		dest_bak++;
	}

	return NULL;
}



void init(mystring *string) {
	string->pstr = NULL;
	string->length = 0;
}


void init_with_length(mystring *string, int length) {
	string->pstr = (char *)calloc(length, sizeof(char));
	string->length = length;
}


void init_with_string(mystring *string, const char *init_string) {
	int length = mystrlen(init_string);
	string->pstr = (char *)calloc(length + 1, sizeof(char));
	mystrcpy(string->pstr, init_string);
	string->length = length + 1;
}


void string_back_add_char(mystring *string, char add_ch) {
	if (mystrlen(string->pstr) + 1 == string->length) {
		string->pstr = realloc(string->pstr, string->length + 1);
		string->length += 1;
		string->pstr[string->length - 2] = add_ch;
		string->pstr[string->length - 1] = '\0';
	} else {
		int cur_length = mystrlen(string->pstr);
		string->pstr[cur_length] = add_ch;
		string->pstr[cur_length + 1] = '\0';
	}
}

void string_back_add_string(mystring *string, char *add_str) {
	int cur_length = mystrlen(string->pstr);
	int add_length = mystrlen(add_str);

	if (cur_length + add_length + 1 > string->length) {
		int need_add_length = cur_length + add_length + 1 - (string->length);
 		string->pstr = (char *)realloc(string->pstr, string->length + need_add_length);
		mystrcat(string->pstr, add_str);
		string->length += need_add_length;
	} else {
		mystrcat(string->pstr, add_str);
	}
}

char *string_find_first_char(mystring *string, char find_char) {
	char *first_find_char = mystrchr(string->pstr, find_char);
	return first_find_char;
}

int main() {

	return 0;
}
