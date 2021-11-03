//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"

namespace sdds {
	Truck::Truck(const char* licenseplate, unsigned year, double capacity, const char* address) :MotorVehicle(licenseplate,year,address) {
		m_capacity = capacity;
		m_cargo = 0;
		cout << "|";
		cout.width(8);
		cout.setf(ios::right);
		cout << m_licenseplate;
		cout.unsetf(ios::right);
		cout << "|" << " |";
		cout.width(20);
		cout.setf(ios::right);
		cout << "Factory";
		cout.unsetf(ios::right);
		cout << " ---> ";
		cout.width(20);
		cout.setf(ios::left);
		cout << address;
		cout.unsetf(ios::left);
		cout << "|" << endl;
	}

	bool Truck::addCargo(double cargo) {

		if (m_cargo >= m_capacity) {
			m_cargo = m_capacity;
			return false;
		}
		else {
			m_cargo += cargo;
			if (m_cargo > m_capacity) {
				m_cargo = m_capacity;
			}
			return true;
		}
	}
	bool Truck::unloadCargo() {
		if (m_cargo != 0) {
			m_cargo = 0;
			return true;
		}
		else {
			return false;
		}
	}

	ostream& Truck::write(ostream& os) const{
		MotorVehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;
	}
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		cin >> m_capacity;
		cout << "Cargo: ";
		cin >> m_cargo;
		return in;
	}
	std::ostream& operator<<(std::ostream& ostr, const Truck& text) {
		return text.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Truck& text) {
		return text.read(istr);
	}
}