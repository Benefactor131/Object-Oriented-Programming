/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Bair Suimaliev
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/22  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "IOAble.h"
#include "Time.h"
#include "utils.h"
using namespace std;

namespace sdds {
	ostream& operator<<(std::ostream& ostr, const IOAble& text) {
		return text.write(ostr);
	}

	istream& operator>>(std::istream& istr, IOAble& text) {
		return text.read(istr);
	}
}