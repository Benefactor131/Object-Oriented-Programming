//Student Name: Bair Suimaliev
//Student email: bsuimaliev@myseneca.ca
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>

namespace sdds {
   class Stats {
       double* m_numbers{ nullptr };
       char* m_filename { nullptr };
       unsigned m_columnWidth;
       unsigned m_noOfColumns;
       unsigned m_precision;
       unsigned m_noOfNumbers;
       void setFilename(const char* fname, bool isCopy = false);
       void setNoOfNumbers();
       void loadData();
       void saveAs(const char* filename)const;
       void setEmpty();
   public:
       Stats(unsigned columnWidth = 15,
           unsigned noOfColumns = 4,
           unsigned precision = 2);
       Stats(const char* filename,
           unsigned columnWidth = 15,
           unsigned noOfColumns = 4,
           unsigned precision = 2);
       ~Stats();
       Stats(const Stats&);
       Stats& operator=(const Stats&);
       double& operator[](unsigned idx);
       double operator[](unsigned idx)const;
       std::ostream& view(std::ostream& ostr)const;
       std::istream& getFile(std::istream& istr);
       operator bool()const;
       void sort(bool ascending);
       unsigned size()const;
       const char* name()const;
       unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
   };
   std::ostream& operator<<(std::ostream& ostr, const Stats& text);
   std::istream& operator>>(std::istream& istr, Stats& text);
}
#endif // !SDDS_TEXTFILE_H__
