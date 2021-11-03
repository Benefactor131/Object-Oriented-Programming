#include "Rectangle.h"
#include "Line.h"
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds {
	Rectangle::Rectangle() : LblShape() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
		int length = (strlen(label) + 2);
		m_width = width;
		m_height = height;
		if (m_height < 3 || m_width < length) {
			m_width = 0;
			m_height = 0;
	    }
	}

	void Rectangle::draw(ostream& x)const {
		if (m_width != 0 && m_height != 0) {
			int len = m_width - 2;
			x << '+';
			for (int i = 0; i < m_width - 2; i++) {
				x << '-';
			}
			x << '+' << endl;
			x << '|';
			x.width(len);
			x.setf(ios::left);
			x << label() << '|' << endl;
			x.unsetf(ios::left);
			for (int i = 0; i < m_height - 3; i++) {
				x << "| ";
				x.width(len);
				x << '|' << endl;
			}
			x << '+';
			for (int i = 0; i < len; i++) {
				x << '-';
			}
			x << '+';
		}
	}

	void Rectangle::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		istr.ignore();
	}
}