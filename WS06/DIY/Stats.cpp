//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "cstring.h"
#include "Stats.h"
using namespace std;

namespace sdds {
    double dummy = 0;

    void Stats::setEmpty() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_numbers;
        m_numbers = 0;
        m_noOfNumbers = 0;
    }

    void Stats::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        if (fname != nullptr)
        {
            if (!isCopy)
            {
                m_filename = new char[strLen(fname) + 1];
                strCpy(m_filename, fname);
            }
            else if (isCopy)
            {
                m_filename = new char[strLen(fname) + 3];
                strCpy(m_filename, "C_");
                strCat(m_filename, fname);
            }
        }
    }
    

    void Stats::setNoOfNumbers() {
        m_noOfNumbers = 0;
        ifstream fin(m_filename);
        string line;
        while (getline(fin, line, ','))
            m_noOfNumbers++;
        if (m_noOfNumbers == 0)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void Stats::loadData() {
        if (m_filename != nullptr)
        {
            if (m_numbers) {
                m_numbers = 0;
                delete[] m_numbers;
            }
            m_numbers = new double[m_noOfNumbers];
            ifstream fin(m_filename);
            unsigned i = 0;
            string str;
            if (fin.is_open())
            {
                for (i = 0; i < m_noOfNumbers; i++) {
                    getline(fin, str, ',');
                    m_numbers[i] = stod(str);
                }
            }
        }
    }

    void Stats::saveAs(const char* fileName)const {
        ofstream dest(fileName);
        unsigned i;

        for (i = 0; i < m_noOfNumbers; i++)
        {
            dest.setf(ios::fixed);

            if (i == m_noOfNumbers - 1) {
                if (m_numbers[i] < 13)
                {
                    dest.precision(m_precision);
                }
                else
                {
                    dest.precision(4);
                }
                dest << m_numbers[i];
            }
            else {
                dest.precision(4);
                dest << m_numbers[i] << ",";
            }
        }
    }

    Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
        setEmpty();
    }

    Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
        if (filename)
        {
            setFilename(filename);
            setNoOfNumbers();
            loadData();
        }
    }

    Stats::~Stats() {
        delete[] m_numbers;
        m_numbers = 0;
        delete[] m_filename;
        m_filename = nullptr;
    }

    Stats::Stats(const Stats& obj) {
        if (m_filename) {
            delete[] m_filename;
            m_filename = nullptr;
        }

        if (obj)
        {
            setFilename(obj.m_filename, true);
            obj.saveAs(m_filename);
            m_columnWidth = obj.m_columnWidth;
            m_noOfColumns = obj.m_noOfColumns;
            m_precision = obj.m_precision;
            m_noOfNumbers = obj.m_noOfNumbers;
            loadData();
        }
    }

    Stats& Stats::operator=(const Stats& obj) {

        if (this != &obj) {
            delete[] m_numbers;
            m_numbers = 0;
            obj.saveAs(m_filename);
            m_columnWidth = obj.m_columnWidth;
            m_noOfColumns = obj.m_noOfColumns;
            m_precision = obj.m_precision;
            m_noOfNumbers = obj.m_noOfNumbers;
            loadData();
        }
        return *this;
    }

    double& Stats::operator[](unsigned idx) {
        double* p = &dummy;

        if (!*this)
        {
            return dummy;
        }
        else {
            p = &m_numbers[idx % m_noOfNumbers];
        }

        return *p;
    }

    double Stats::operator[](unsigned idx)const {
        if (!*this)
        {
            return dummy;
        }
        if (idx > m_noOfNumbers) {
            return m_numbers[idx % m_noOfNumbers];
        }
        else {
            return m_numbers[idx];
        }
    }

    std::ostream& Stats::view(std::ostream& ostr)const {
        if (m_numbers > 0 && m_filename != nullptr && m_noOfNumbers > 0)
        {
            ostr << m_filename << endl;
            for (int i = 0; i < strLen(m_filename); i++)
            {
                ostr << "=";
            }

            ostr << "\n\n";

            for (unsigned i = 0; i < m_noOfNumbers; i++)
            {

                ostr.width(m_columnWidth);
                ostr.setf(ios::right);
                ostr.setf(ios::fixed);
                ostr.precision(m_precision);
                ostr << m_numbers[i];
                ostr.unsetf(ios::right);
                if ((i + 1) % m_noOfColumns == 0 && i != 0 && i != (m_noOfNumbers - 1)) {
                    ostr << endl;
                }
                

            }
            ostr << endl;
            ostr << "Total of " << m_noOfNumbers << " listed!" << endl;
        }

        return ostr;
    }

    std::istream& Stats::getFile(std::istream& istr) {
        string str;
        getline(istr, str);
        delete[] m_filename;
        m_filename = new char[strLen(str.c_str()) + 1];
        strCpy(m_filename, str.c_str());
        setNoOfNumbers();
        loadData();
        return istr;
    }

    Stats::operator bool()const {
        if (m_numbers != 0 && m_filename != nullptr && m_noOfNumbers > 0)
        {
            return true;
        }
        return false;
    }

    void Stats::sort(bool ascending) {
        double temp;
        if (!ascending)
        {
            for (unsigned i = 0; i < m_noOfNumbers; i++)
            {
                for (unsigned k = 0; k < m_noOfNumbers; k++)
                {
                    if (m_numbers[i] > m_numbers[k]) {
                        temp = m_numbers[i];
                        m_numbers[i] = m_numbers[k];
                        m_numbers[k] = temp;
                    }
                }
            }
        }
        else {
            for (unsigned i = 0; i < m_noOfNumbers; i++)
            {
                for (unsigned k = 0; k < m_noOfNumbers; k++)
                {
                    if (m_numbers[i] < m_numbers[k]) {
                        temp = m_numbers[i];
                        m_numbers[i] = m_numbers[k];
                        m_numbers[k] = temp;
                    }
                }
            }
        }
    }

    unsigned Stats::size()const {
        return m_noOfNumbers;
    }

    const char* Stats::name()const {
        return m_filename;
    }

    unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
        unsigned counter = 0;
        if (min != 1) {
            ostr << endl;
        }
        for (unsigned i = 0; i < m_noOfNumbers; i++)
        {
            if (m_numbers[i] >= min && m_numbers[i] <= max) {
                ostr.width(m_columnWidth);
                ostr.setf(ios::right);
                ostr.setf(ios::fixed);
                ostr.precision(m_precision);
                ostr.unsetf(ios::right);
                ostr << m_numbers[i];
                counter++;
                if (counter % m_noOfColumns == 0 && counter != 0) {
                    ostr << endl;
                }
            }
        }
        if (counter != 0) {
            ostr << endl;
            ostr << "Total of " << counter << " numbers are between " << min << " and " << max << endl;
        }
        return counter;
    }

    std::ostream& operator<<(std::ostream& ostr, const Stats& text) {
        return text.view(ostr);
    }

    std::istream& operator>>(std::istream& istr, Stats& text) {
        return text.getFile(istr);
    }

}