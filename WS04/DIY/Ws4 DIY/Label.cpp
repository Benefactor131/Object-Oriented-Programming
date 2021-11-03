//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <string>
#include "Label.h"
#include "cstring.h"
#define LIMIT 70

using namespace std;

namespace sdds {
	int noOfLabels = 1;

	Label::Label() {
		length = 0;
		strCpy(this->ch_top_left_corner, "+");
		strCpy(this->ch_top, "-");
		strCpy(this->ch_top_right_corner, "+");
		strCpy(this->ch_right, "|");
		strCpy(this->ch_bottom_right_corner, "+");
		strCpy(this->ch_bottom, "-");
		strCpy(this->ch_bottom_left_corner, "+");
		strCpy(this->ch_left, "|");
		lbl = nullptr;
	}

	Label::Label(const char* frameArg) {
		length = 0;
		ch_top_left_corner[0] = frameArg[0];
		ch_top_left_corner[1] = '\0';
		ch_top[0] = frameArg[1];
		ch_top[1] = '\0';
		ch_top_right_corner[0] = frameArg[2];
		ch_top_right_corner[1] = '\0';
		ch_right[0] = frameArg[3];
		ch_right[1] = '\0';
		ch_bottom_right_corner[0] = frameArg[4];
		ch_bottom_right_corner[1] = '\0';
		ch_bottom[0] = frameArg[5];
		ch_bottom[1] = '\0';
		ch_bottom_left_corner[0] = frameArg[6];
		ch_bottom_left_corner[1] = '\0';
		ch_left[0] = frameArg[7];
		ch_left[1] = '\0';
		lbl = nullptr;
	}

	Label::Label(const char* frameArg, const char* content) {
		lbl = nullptr;
		length = strLen(content);
		ch_top_left_corner[0] = frameArg[0];
		ch_top_left_corner[1] = '\0';
		ch_top[0] = frameArg[1];
		ch_top[1] = '\0';
		ch_top_right_corner[0] = frameArg[2];
		ch_top_right_corner[1] = '\0';
		ch_right[0] = frameArg[3];
		ch_right[1] = '\0';
		ch_bottom_right_corner[0] = frameArg[4];
		ch_bottom_right_corner[1] = '\0';
		ch_bottom[0] = frameArg[5];
		ch_bottom[1] = '\0';
		ch_bottom_left_corner[0] = frameArg[6];
		ch_bottom_left_corner[1] = '\0';
		ch_left[0] = frameArg[7];
		ch_left[1] = '\0';
		if (content != nullptr && strLen(content) <= LIMIT) {
			this->lbl = new char[length + 1];
			strnCpy(lbl, content, length);
		}
	}

	Label::~Label() {
		delete[] lbl;
	}

	void Label::readLabel() {
		int len = 0;
		char temp[LIMIT];
		cout << "Enter label number " << noOfLabels << endl;
		cin.ignore(2);
		cin.getline(temp, LIMIT + 1);
		len = strLen(temp);
		lbl = new char[len + 1];
		strnCpy(lbl, temp, len);
		lbl[len] = '\0';
		length = len;
		noOfLabels++;
	}

	std::ostream& Label::printLabel()const {
		if (lbl != nullptr)
		{
			cout << ch_top_left_corner;
			for (int j = 0; j < length + 2; j++) {
				cout << ch_top;
			}
			cout << ch_top_right_corner << endl;

			cout << ch_left;
			for (int i = 0; i < length + 2; i++)
			{
				cout << ' ';
			}
			cout << ch_right << endl;

			cout << ch_left << ' ' << lbl << ' ' << ch_right << endl;

			cout << ch_left;
			for (int i = 0; i < length + 2; i++)
			{
				cout << ' ';
			}
			cout << ch_right << endl;

			cout << ch_bottom_left_corner;
			for (int j = 0; j < length + 2; j++) {
				cout << ch_bottom;
			}
			cout << ch_bottom_right_corner;
		}

		return cout;
	}
}
