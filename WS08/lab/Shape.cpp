#include "Shape.h"
#include <iostream>
using namespace std;
namespace sdds {
	
	ostream& operator<<(ostream& ostr, const Shape& text) {
		text.draw(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Shape& text) {	
		text.getSpecs(istr);
		return istr;
	}
}