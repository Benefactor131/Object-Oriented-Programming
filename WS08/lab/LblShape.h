#pragma once
#pragma once
#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__
#include <iostream>
#include "Shape.h"
namespace sdds
{
	class LblShape: public Shape{
		char* m_label{nullptr};
	protected:
		char* label() const;
	public:
		LblShape() : m_label{ nullptr } {};
		LblShape(const char*);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape& obj) = delete;
		void getSpecs(istream&);		
	};


}

#endif 