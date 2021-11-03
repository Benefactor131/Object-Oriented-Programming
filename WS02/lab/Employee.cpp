//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"


using namespace std;

namespace sdds {

   int flag = 1;
   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(struct Employee &emp) {
      bool ok = false;
      char name[128];
      int length;
      if (read(emp.m_empNo) == true && read(emp.m_salary) == true && read(name) == true) {
          length = strLen(name) + 1;
          emp.m_name = new char[length];
          strCpy(emp.m_name, name);
          ok = true;
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i;
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          employees = new struct Employee[noOfEmployees];
          for (i = 0; i < noOfEmployees; i++)
          {
              load(employees[i]);
          }
          if (i == noOfEmployees)
          {
              ok = true;
          }
          else
          {
              cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
          }
          closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(struct Employee &emp) {
           cout << flag << "- " << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
           flag++;
   }

   void display() {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       for (int i = 0; i < noOfEmployees; i++)
       {
           display(employees[i]);
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       delete[] employees;
   }


}