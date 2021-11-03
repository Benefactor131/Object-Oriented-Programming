#include "Line.h"
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds {
	Line::Line(): LblShape() {
		m_length = 0;
	}

	Line::Line(const char* label, int length): LblShape(label) {
		m_length = length;
	}

	void Line::draw(ostream& ostr)const {
		if (m_length > 0 && label() != nullptr) { 
			ostr << label() << endl;
			for (int i = 0; i < m_length; i++) {
				ostr << '=';
			}
		}
	}

	void Line::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore();
	}
}