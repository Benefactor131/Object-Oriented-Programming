#include <iostream>
#include "cstring.h"

using namespace std;
namespace sdds {
	void strCpy(char* des, const char* src) {
		while (*src != '\0')
		{
			*des = *src;
			des++;
			src++;
		}
		*des = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {
		for (int i = 0; i < len; i++)
		{
			des[i] = src[i];
		}
	}

	int strCmp(const char* s1, const char* s2) {
		if (s1 == s2)
			return 0;
		
		else if (s1 > s2)
			return 1;
		
		else if (s1 < s2) 
			return -1;

		return 0;
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		for (int i = 0; i < len; i++) {
			if (s1[i] > s2[i])
			{
				return 1;
			}
			else if (s1[i] < s2[i]) {
				return -1;
			}
		}
		return 0;
	}

	int strLen(const char* s) {
		int length = 0;
		while (s[length] != '\0')
		{
			length++;
		}
		return length;
	}

	const char* strStr(const char* str1, const char* str2) {
		if(*str2 == '\0')
			return str1;

		for (int i = 0; i < strLen(str1); i++)
		{
			if (*(str1 + i) == *str2)
			{
				const char* ptr = strStr(str1 + i + 1, str2 + 1);
				return (ptr) ? ptr - 1 : NULL;
			}
		}

		return NULL;
	}
	
	void strCat(char* des, const char* src) {
		int i, j;
		for (i = 0; des[i] != '\0'; i++); 

		for (j = 0; src[j] != '\0'; j++) {
			des[i + j] = src[j];
		}

		des[i + j] = '\0';
	}
}