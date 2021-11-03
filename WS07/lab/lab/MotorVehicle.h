//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#pragma once
#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>

using namespace std;

namespace sdds {
	
	class MotorVehicle {
	protected:
		char m_licenseplate[10];
		char m_address[65];
		unsigned m_year;
	public:
		MotorVehicle(const char* licenseplate, unsigned year, const char* address = "Factory");
		void moveTo(const char* address);
		const char* getLicensePlate()const;
		const char* getAddress()const;
		unsigned getYear()const;
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& text);
	std::istream& operator>>(std::istream& istr, MotorVehicle& text);
}

#endif 