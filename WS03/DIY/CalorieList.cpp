//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;

namespace sdds {
	void CalorieList::setEmpty() {
		m_products = nullptr;
	}

	bool CalorieList::isValid()const {
		int counter = 0;
		bool ok;
		if (!(m_products == NULL)) {
			for (int i = 0; i < m_noOfProducts; i++)
			{
				if (m_products[i].isValid()) {
					counter++;
				}
			}
			if (counter == m_noOfProducts) {
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

	int CalorieList::totalCalories()const {
		double total_cals = 0.0;
		double cals_ = 0.0;
		for (int i = 0; i < m_noOfProducts; i++) {
			cals_ = m_products[i].caloriesCount();
			total_cals += cals_;
		}
		return total_cals;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "|    Total Calories for today: ";
			cout.width(8);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << totalCalories() << " |            |" << endl;
			cout.unsetf(ios::right);
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int noOfItems) {
		if (noOfItems <= 0) {
			setEmpty();
		}
		else {
			m_noOfProducts = noOfItems;
			m_productsAdded = 0;
			m_products = new Product[m_noOfProducts];
			for (int i = 0; i < m_noOfProducts; i++)
			{
				m_products[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* product_name, int calories, int when) {
		if (product_name == nullptr) {
			product_name = "";
		}
		if (m_productsAdded < m_noOfProducts) {
			m_products[m_productsAdded].set(product_name, calories, when);
			m_productsAdded++;
			return true;
		}
		else {
			return false;
		}
	}

	void CalorieList::display()const {
		Title();
		for (int i = 0; i < m_noOfProducts; i++) {
			m_products[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] m_products;
	}
}
