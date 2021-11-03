#pragma once
#pragma once
#ifndef SDDS_RECTANGLE_H__
#define SDDS_RECTANGLE_H__
#include <iostream>
#include "LblShape.h"

namespace sdds
{
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char*, int, int);
		void draw(ostream&)const;
		void getSpecs(istream&);
	};
}

#endif 