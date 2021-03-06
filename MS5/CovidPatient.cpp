/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
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
#include "CovidPatient.h"

using namespace std;

namespace sdds {
   int nextCovidTicket = 1;

   
   CovidPatient::CovidPatient() : Patient(nextCovidTicket, false) {
	   nextCovidTicket++;
   }

   char CovidPatient::type() const {
	   return 'C';
   }

   istream& CovidPatient::csvRead(istream& istr) {
	   Patient::csvRead(istr);
	   nextCovidTicket = number() + 1;
	   return istr;
   }

   ostream& CovidPatient::write(ostream& ostr)const {
	   if (fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr);
		   ostr << endl; 
	   }

	   return ostr;
   }

   istream& CovidPatient::read(istream& istr) {
	   if (fileIO()) {
		   csvRead(istr);
	   }
	   else {
		   Patient::read(istr);
	   }

	   return istr;
   }

}