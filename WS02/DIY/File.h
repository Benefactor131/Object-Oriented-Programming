//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char*);
   bool read(int&);

}
#endif // !SDDS_FILE_H_
