//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#include "cstring.h"
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

	int strLen(const char* s) {
		int length = 0;
		while (s[length] != '\0')
		{
			length++;
		}
		return length;
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