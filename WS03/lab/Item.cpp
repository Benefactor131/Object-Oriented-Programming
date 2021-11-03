//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds {

	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
	}

	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (price <= 0 || name == nullptr)
		{
			setEmpty();
		}
		setName(name);
		m_price = price;
		m_taxed = taxed;
		
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		if (m_taxed)
		{
			return m_price * 0.13;
		}
		return 0.0;
	}

	bool Item::isValid()const {
		bool ok;
		if (!(m_price <= 0) && (m_itemName[0] != '\0')) {
			ok = true;
		}
		else {
			ok = false;
		}

		return ok;
	}

	void Item::display()const {

		if (isValid()) {
			cout << "| ";
			cout.fill('.');
			cout.width(20);
			cout.setf(ios::left);
			cout << m_itemName;
			cout << " | ";
			cout.fill(' ');
			cout.width(7);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price << " | ";
			cout.unsetf(ios::right);

			if (m_taxed) {
				cout << "Yes" << " |" << endl;
			}
			else {
				cout << "No " << " |" << endl;
			}
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}