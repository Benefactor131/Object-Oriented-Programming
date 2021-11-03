#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace sdds {

	char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape(const char* label) {
		if (m_label) {
			delete[] m_label;
			m_label = nullptr;
		}
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& istr) {
		string str;
		if (m_label) {
			delete[] m_label;
			m_label = nullptr;
		}
		getline(istr, str, ',');
		m_label = new char[strlen(str.c_str()) + 1];
		strcpy(m_label, str.c_str());
	}
}