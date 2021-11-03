//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds {
	
	MotorVehicle::MotorVehicle(const char* licenseplate, unsigned year, const char* address) {
		m_year = year;
		strCpy(m_licenseplate, licenseplate);
		strCpy(m_address, address);
	}

	const char* MotorVehicle::getLicensePlate() const {
		return m_licenseplate;
	}

	const char* MotorVehicle::getAddress() const{
		return m_address;
	}

	unsigned MotorVehicle::getYear() const{
		return m_year;
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(m_address, address)) {
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_licenseplate;
			cout.unsetf(ios::right);
			cout << "|" << " |";
			cout.width(20); 
			cout.setf(ios::right);
			cout << m_address;
			cout.unsetf(ios::right);
			cout << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout.unsetf(ios::left);
			cout << "|" << endl;

			strCpy(m_address, address);
		}
	}

	ostream& MotorVehicle::write(ostream& os) const {
		os << "| " << m_year << " | " << m_licenseplate << " | " << m_address;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		cin >> m_year;
		cout << "License plate: ";
		cin >> m_licenseplate; 
		cout << "Current location: ";
		cin >> m_address;
		return in;
	}
	
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& text) {
		return text.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, MotorVehicle& text) {
		return text.read(istr);
	}


}