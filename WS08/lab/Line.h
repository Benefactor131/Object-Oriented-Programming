#pragma once
#ifndef SDDS_LINE_H__
#define SDDS_LINE_H__
#include <iostream>
#include "LblShape.h"
namespace sdds
{
	class Line: public LblShape {
		int m_length;
	public:
		Line();
		Line(const char*, int);
		void draw(ostream&)const;
		void getSpecs(istream&);
	};

}

#endif 