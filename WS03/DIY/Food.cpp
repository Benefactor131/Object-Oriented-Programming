//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Food.h"

using namespace std;

namespace sdds {

	void Product::setName(const char* name) {
		strnCpy(foodName, name, 30);
	}

	void Product::setEmpty() {
		cal_num = 0;
		foodName[0] = '\0';
	}

	void Product::set(const char* name, int calories, int when) {
		if (calories <= 0 || calories >= 3000 || name == nullptr)
		{
			setEmpty();
		}
		setName(name);
		cal_num = calories;
		mealTime = when;
	}

	int Product::caloriesCount()const {
		return cal_num;
	}

	bool Product::isValid()const {
		bool ok;
		if (!(cal_num <= 0 || cal_num >= 3000) && !(foodName[0] == '\0') && !(mealTime <= 0 || mealTime > 4)) {
			ok = true;
		}
		else {
			ok = false;
		}

		return ok;
	}

	void Product::display()const {
		if (isValid()) {
			cout << "| ";
			cout.fill('.');
			cout.width(30);
			cout.setf(ios::left);
			cout << foodName;
			cout << " | ";
			cout.fill(' ');
			cout.width(4);
			cout.setf(ios::right);
			cout << cal_num << " | ";
			cout.unsetf(ios::right);

			printMealTime();
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

	void Product::printMealTime()const {
		if (mealTime == 1) {
			cout.fill(' ');
			cout.width(10);
			cout.setf(ios::left);
			cout << "Breakfast" << " |" << endl;
		}
		else if(mealTime == 2) { 
			cout.fill(' ');
			cout.width(10);
			cout.setf(ios::left);
			cout << "Lunch" << " |" << endl;
		}
		else if (mealTime == 3) {
			cout.fill(' ');
			cout.width(10);
			cout.setf(ios::left);
			cout << "Dinner" << " |" << endl;
		}
		else if (mealTime == 4) {
			cout.fill(' ');
			cout.width(10);
			cout.setf(ios::left);
			cout << "Snack" << " |" << endl;
		}
	}
}
