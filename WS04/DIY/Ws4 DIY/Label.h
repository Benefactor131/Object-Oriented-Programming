//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds {
	class Label {
		char ch_top_left_corner[2];
		char ch_top[2];
		char ch_top_right_corner[2];
		char ch_right[2];
		char ch_bottom_right_corner[2];
		char ch_bottom[2];
		char ch_bottom_left_corner[2];
		char ch_left[2];
		char* lbl;
		int length;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}

#endif // SDDS_LABEL_H

