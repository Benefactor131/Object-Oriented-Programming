//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator ~()const;
        Account& operator=(int);
        Account& operator=(Account&);
        Account& operator+=(double);
        Account& operator-=(double);
        Account& operator<<(Account&);
        Account& operator>>(Account&);

    };
    double operator+(const Account&, const Account&);
    double& operator+=(double&, const Account&);

}
#endif // SDDS_ACCOUNT_H