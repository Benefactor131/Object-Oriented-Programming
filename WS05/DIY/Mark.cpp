//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {
    void Mark::setEmpty() {
		mark = 0;
		gpa = 0;
		grade = '\0';
		valid = false;
	}

	void Mark::varSet() {
		if (0 <= mark && mark < 50)
		{
			gpa = 0;
			grade = 'F';
			valid = true;
		}
		else if (50 <= mark && mark < 60) {
			gpa = 1;
			grade = 'D';
			valid = true;
		}
		else if (60 <= mark && mark < 70) {
			gpa = 2;
			grade = 'C';
			valid = true;
		}
		else if (70 <= mark && mark < 80) {
			gpa = 3;
			grade = 'B';
			valid = true;
		}
		else if (80 <= mark && mark < 100) {
			gpa = 4;
			grade = 'A';
			valid = true;
		}
		else
		{
			setEmpty();
			grade = 'X';
		}
	}

    Mark::Mark() {
		mark = 0;
		gpa = 0;
		grade = 'F';
		valid = true;
    }

    Mark::Mark(int mark_) {
        this->mark = mark_;
		varSet();
    }

    Mark::operator int()const {
        return mark;
    }
    
    Mark::operator double() const{
        return gpa;
    }

    Mark::operator char()const {
        return grade;
    }

    bool Mark::operator~()const {
		return valid;
    }


    Mark& Mark::operator+=(int num) {
        if (~*this && num >= 0) {
            mark += num;
			varSet();
        }
        return *this;
    }

	Mark& Mark::operator=(int value) {
		if (value >= 0 && value <= 100) {
			mark = value;
			varSet();
		}	
		else {
			setEmpty();
			grade = 'X';
		}
		return *this;
	}

    int& operator+=(int& num, const Mark& mk) {
        int& val = num;
        val += int(mk);
        return val;
    }

}