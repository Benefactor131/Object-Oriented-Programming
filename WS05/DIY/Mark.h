//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>

namespace sdds {
    class Mark {
        int mark;
        double gpa;
        char grade;
        bool valid;
        void setEmpty();
    public:
        Mark();
        Mark(int);
        void varSet();
        operator int()const;
        operator double()const;
        operator char()const;
        bool operator~()const;
        Mark& operator+=(int);
        Mark& operator=(int);
    };

    int& operator+=(int&, const Mark&);
}
#endif // SDDS_MARK_H