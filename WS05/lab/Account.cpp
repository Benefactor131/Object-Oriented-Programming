//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }
    Account::operator bool()const {
        bool valid = ((m_number >= 10000 && m_number <= 99999) && m_balance >= 0);
        return valid;
    }

    Account::operator int()const {
        return m_number;
    }

    Account::operator double()const {
        return m_balance;
    }

    bool Account::operator ~() const {
        return m_number == 0;
    }

    Account& Account::operator=(int num) {
        if (~*this == true) {
            if (num < 10000 || num > 99999) {
                setEmpty();
            }
            else {
                m_number = num;
            }
        }
        return *this;
    }

    Account& Account::operator=(Account &acc) {
        if (~*this == true && acc) {
            this->m_number = acc.m_number;
            this->m_balance = acc.m_balance;
            acc.m_number = 0;
            acc.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator+=(double num) {
        if (*this && num > 0)
            m_balance += num;
        return *this;
    }

    Account& Account::operator-=(double num) {
        if (this->m_balance >= num && num > 0 && *this)
            this->m_balance -= num;
        return *this;
    }

    Account& Account::operator<<(Account &C) {
        if (this->m_number != C.m_number) {
            this->m_balance += C.m_balance;
            C.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account &C) {
        if (this->m_number != C.m_number) {
            C.m_balance += this->m_balance;
            this->m_balance = 0.0;
        }

        return *this;
    }

    double operator+(const Account &A, const Account &B) {
        double sum;
        if (A && B) {
            sum = double(A) + double(B);
        }
        else {
            sum = 0;
        }
        return sum;
    }

    double& operator+=(double& num, const Account &acc) {
        double &sum = num;
        sum += double(acc);
        return sum;
    }
}