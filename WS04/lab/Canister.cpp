//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. 
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
	const double PI = 3.14159265;

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_diameter = 10.0;
		m_hieght = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}
   
	bool Canister::isEmpty()const {
		if (m_contentVolume < 0.00001)
		{
			return true;
		}
		return false;
	}

	bool Canister::hasSameContent(const Canister& C)const {
		if ((strCmp(m_contentName, C.m_contentName) == 0) && (m_contentName != nullptr && C.m_contentName != nullptr))
		{
			return true;
		}
		return false;
	}

	void Canister::setName(const char* Cstr) {
		
		if (m_usable == true && Cstr != nullptr)
		{
			int length = 0;
			length = strLen(Cstr) + 1;
			this->m_contentName = new char[length];
			strCpy(m_contentName, Cstr);
		}
	}

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double hieght, double diameter, const char* contentName) {
		setToDefault();
		if ((hieght >= 10 && hieght <= 40) && (diameter >= 10 && diameter <= 30))
		{
			m_hieght = hieght;
			m_diameter = diameter;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}

	void Canister::clear() {
		this->~Canister();
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	Canister::~Canister() {
		delete[] m_contentName;
	}

	double Canister::capacity()const {
		double capacity_;
		capacity_ = PI * (m_hieght - 0.267) * (m_diameter / 2) * (m_diameter / 2);
		return capacity_;
	}

	double Canister::volume()const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr)
		{
			m_usable = false;
		}
		else if (isEmpty()) {
			setName(contentName);
		}
		else if (!hasSameContent(contentName)) {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0 && (quantity + volume()) <= capacity())
		{
			m_contentVolume += quantity;
		}
		else
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (C.volume() > (capacity() - volume()))
		{
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();

		}
		else
		{
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}

	std::ostream& Canister::display()const {
		cout.width(7);
		cout.setf(ios::right);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << capacity() << "cc (" << m_hieght << 'x' << m_diameter << ") Canister";
		cout.unsetf(ios::right);
		if (!m_usable)
		{
			cout << " of Unusable content, discard!";
		}
		else
		{
			if (m_contentName != nullptr)
			{
				cout << " of ";
				cout.width(7);
				cout.setf(ios::right);
				cout.setf(ios::fixed);
				cout.precision(1);
				cout << volume() << "cc   " << m_contentName;
			}
			
		}
		return cout;
	}
}