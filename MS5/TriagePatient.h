/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
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
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds {
	class TriagePatient :public Patient {
		char* m_symptoms{ nullptr };
	public:
		TriagePatient();
		~TriagePatient();
		virtual char type() const;
		ostream& csvWrite(ostream& ostr)const;
		istream& csvRead(istream& istr);
		ostream& write(ostream& ostr)const;
		istream& read(istream& istr);
	};

}
#endif // !SDDS_TRIAGEPATIENT_H


