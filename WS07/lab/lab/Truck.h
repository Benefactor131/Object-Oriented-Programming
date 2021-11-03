//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#pragma once
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"

using namespace std;
namespace sdds {
	class Truck:public MotorVehicle {
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* licenseplate, unsigned year, double capacity, const char* address = "Factory");
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os)const;
		istream& read(istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const Truck& text);
	std::istream& operator>>(std::istream& istr, Truck& text);
}

#endif 