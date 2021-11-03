/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int numb, bool flag) : m_ticket(numb) {
		m_ticket = numb;
		m_flag = flag;
	}

	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Patient::fileIO() const {
		return m_flag;
	}

	void Patient::fileIO(bool flag) {
		m_flag = flag;
	}

	bool Patient::operator==(char ch) const {
		return type() == ch ? true : false;
	}

	bool Patient::operator==(const Patient& obj) const {
		if (type() == obj.type())
		{
			return true;
		}

		return false;
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Patient::operator Time() const {
		return Time(m_ticket);
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(ostream& ostr)const {
		ostr << type() << ',' << m_name << ',' << m_ohip << ',';
		m_ticket.csvWrite(ostr);

		return ostr;
	}

	istream& Patient::csvRead(istream& istr) {
		string str;
		getline(istr, str, ',');
		if (str.length() != 0)
		{
			delete[] m_name;
			m_name = new char[strlen(str.c_str()) + 1];
			strcpy(m_name, str.c_str());
			istr >> m_ohip;
			istr.ignore();
			m_ticket.csvRead(istr);
		}
		return istr;
	}

	ostream& Patient::write(ostream& ostr)const {
		int length = strlen(m_name);
		m_ticket.write(ostr);
		ostr << endl;
		for (int i = 0; i < length; i++)
		{
			if (i < 25)
			{
				ostr << m_name[i];
			}
			else {
				break;
			}
		}

		return ostr << ", OHIP: " << m_ohip;
	}

	istream& Patient::read(istream& istr) {
		cout << "Name: ";
		string str;
		getline(istr, str, '\n');
		delete[] m_name;
		m_name = new char[strlen(str.c_str()) + 1];
		strcpy(m_name, str.c_str());
		m_ohip = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ");

		return istr;
	}

}