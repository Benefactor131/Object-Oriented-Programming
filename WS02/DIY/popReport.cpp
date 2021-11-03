// Workshop 2: 
// Version: 0.9
// Date: 2021/01/23
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
// Do not modify your code
// Student Name: Bair Suimaliev
// Student ID: 159350198
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////
#include "Population.h"
using namespace sdds;
int main() {
   if (load("PCpopulations.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}