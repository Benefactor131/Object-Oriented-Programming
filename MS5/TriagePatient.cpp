/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"

using namespace std;

namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket, false) {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }

   char TriagePatient::type() const {
	   return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& ostr)const {
	   Patient::csvWrite(ostr);
	   return ostr << ',' << m_symptoms;
   }

   istream& TriagePatient::csvRead(istream& istr) {
	   Patient::csvRead(istr);
	   istr.ignore();
	   delete[] m_symptoms;
	   m_symptoms = getcstr("", istr, '\n');
	   nextTriageTicket = number() + 1;
	   return istr;
   }

   ostream& TriagePatient::write(ostream& ostr)const {
	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl << "Symptoms: " << m_symptoms << endl;
	   }
	   return ostr;
   }

   istream& TriagePatient::read(istream& istr) {
	   if (fileIO()) {
		   csvRead(istr);
	   }
	   else {
		   Patient::read(istr);
		   delete[] m_symptoms;
		   m_symptoms = getcstr("Symptoms: ");
	   }
	   return istr;
   }

   TriagePatient::~TriagePatient() {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }

}