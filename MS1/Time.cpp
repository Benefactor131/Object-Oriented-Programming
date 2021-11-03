//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow() {
        m_min = getTime();

        return *this;
    }

    Time::Time(unsigned int min) {
        m_min = min;
    }

    std::ostream& Time::write(std::ostream& ostr) const {

        if ((m_min / 60) < 10)
        {
            ostr << 0 << (m_min / 60);
        }
        else {
            ostr << (m_min / 60);
        }

        cout << ':';

        if ((m_min % 60) < 10)
        {
            ostr << 0 << (m_min % 60);
        }
        else {
            ostr << (m_min % 60);
        }

        return ostr;
    }

    std::istream& Time::read(std::istream& istr) {
        char delimiter = ':';
        int hours = 0;
        int minutes = 0;

        cin >> hours >> delimiter >> minutes;

        if (hours < 0)
        {
            istr.setstate(ios::failbit);
        }

        if (delimiter != ':') {
            istr.setstate(ios::failbit);
        }

        if (minutes < 0)
        {
            istr.setstate(ios::failbit);
        }

        m_min = (hours * 60) + minutes;

        return istr;
    }


    Time& Time::operator-=(const Time& D) {
        while (m_min < D.m_min)
        {
            m_min += 1440;
        }
        m_min -= D.m_min;

        return *this;
    }

    Time Time::operator-(const Time& D)const {
        Time obj;
        obj.m_min = m_min;
        while (obj.m_min < D.m_min)
        {
            obj.m_min += 1440;
        }
        obj.m_min -= D.m_min;

        return obj;
    }

    Time& Time::operator+=(const Time& D) {
        m_min += D.m_min;

        return *this;
    }

    Time Time::operator+(const Time& D)const {
        Time obj;
        obj.m_min = m_min + D.m_min;

        return obj;
    }

    Time& Time::operator=(unsigned int val) {
        m_min = val;

        return *this;
    }

    Time& Time::operator *= (unsigned int val) {
        m_min *= val;

        return *this;
    }

    Time& Time::operator /= (unsigned int val) {
        m_min /= val;

        return *this;
    }

    Time Time::operator *(unsigned int val)const {
        Time obj;
        obj.m_min = m_min * val;

        return obj;
    }

    Time Time::operator /(unsigned int val)const {
        Time obj;
        obj.m_min = m_min / val;

        return obj;
    }

    Time::operator unsigned int()const {
        return m_min;
    }

    Time::operator int()const {
        int min = m_min;

        return min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D) {
        return D.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, Time& D) {
        return D.read(istr);
    }

}