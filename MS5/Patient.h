/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author	Bair Suimaliev
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/27  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#pragma once
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "Ticket.h"
using namespace std;
namespace sdds {
	class Patient:public IOAble {
		char* m_name{nullptr};
		int m_ohip;
		Ticket m_ticket;
		bool m_flag;
	public:
		Patient(int numb = 0, bool flag = false);
		~Patient();
		Patient(const Patient& temp_obj) = delete;
		Patient& operator=(const Patient& temp_obj) = delete;
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool flag);
		bool operator==(char) const;
		bool operator==(const Patient&) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		ostream& csvWrite(ostream& ostr)const;
		istream& csvRead(istream& istr);
		ostream& write(ostream& ostr)const;
		istream& read(istream& istr);
	};
}
#endif // !SDDS_PATIENT_H_
