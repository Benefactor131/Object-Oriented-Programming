//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const {
		int counter = 0;
		bool ok;
		if (!(m_title[0] == '\0') && !(m_items == NULL)) {
			for (int i = 0; i < m_noOfItems; i++)
			{
				if (m_items[i].isValid()) {
					counter++;
				}
			}
			if (counter == m_noOfItems) {
				ok = true;
			}
			else {
				ok = false;
			}
		}
		else {
			ok = false;
		}

		return ok;
	}

	double Bill::totalTax()const {
		double total_tax = 0.0;
		double tx = 0.0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			tx = m_items[i].tax();
			total_tax += tx;
		}
		return total_tax;
	}

	double Bill::totalPrice()const {
		double total_price = 0.0;
		double price = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			price = m_items[i].price();
			total_price += price;
		}
		return total_price;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title << " |" << endl;
			cout.unsetf(ios::left);
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() << " |" << endl;
			cout.unsetf(ios::right);
			cout << "|              Total Price: ";
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalPrice() << " |" << endl;
			cout.unsetf(ios::right);
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() + totalPrice() << " |" << endl;
			cout.unsetf(ios::right);
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		if (!title || noOfItems <= 0) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		if (item_name == nullptr) {
			item_name = "";
		}
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			return true;
		}
		else {
			return false;
		}
	}

	void Bill::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate() {
		delete[] m_items;
	}
}
