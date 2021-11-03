//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include "LabelMaker.h"

using namespace std;

namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
		num_of_labels = noOfLabels;
		lbls = new Label[noOfLabels];
	}

	void LabelMaker::readLabels() {
		cout << "Enter " << num_of_labels << " labels:" << endl;
		for (int i = 0; i < num_of_labels; i++)
		{
			lbls[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {
		for (int i = 0; i < num_of_labels; i++)
		{
			lbls[i].printLabel();
			cout << endl;
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] lbls;
	}
}