#pragma once
#pragma once
#ifndef SDDS_SHAPE_H__
#define SDDS_SHAPE_H__
#include <iostream>
using namespace std;
namespace sdds
{
	class Shape{
	public:
		virtual ~Shape() {};
		virtual void draw(ostream&)const = 0;
		virtual void getSpecs(istream&) = 0;
	};

	ostream& operator<<(ostream&s, const Shape&);
	istream& operator>>(istream&, Shape&);
}
#endif 