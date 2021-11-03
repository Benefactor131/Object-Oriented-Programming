/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
Version 1.0
Author	Bair Suimaliev
Revision History
-----------------------------------------------------------
Date      Reason
2020/4/02  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#pragma once
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds {
	class CovidPatient :public Patient {
	public:
		CovidPatient();
		virtual char type() const;
		istream& csvRead(istream& istr);
		istream& read(istream& istr);
		ostream& write(ostream& ostr)const;
	};
	
}
#endif // !SDDS_COVIDPATIENT_H_



