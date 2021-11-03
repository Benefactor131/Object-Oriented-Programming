/* Citation and Sources...
Final Project Milestone 3
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
	   string str;
	   getline(istr, str, '\n');
	   delete[] m_symptoms;
	   m_symptoms = new char[strlen(str.c_str()) + 1];
	   strcpy(m_symptoms, str.c_str());
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
		   delete[] m_symptoms;
		   Patient::read(istr);
		   cout << "Symptoms: ";
		   string str;
		   getline(istr, str, '\n');
		   delete[] m_symptoms;
		   m_symptoms = new char[strlen(str.c_str()) + 1];
		   strcpy(m_symptoms, str.c_str());
	   }
	   return istr;
   }

   TriagePatient::~TriagePatient() {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }

}