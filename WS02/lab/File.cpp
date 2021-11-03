//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
  
   bool read(char* c) {
      int suc;
      suc = fscanf(fptr, "%[^\n]\n", c);
      return (suc > 0) ? true : false;
   }
   bool read(int &id) {
      int suc;
      suc = fscanf(fptr, "%d,", &id);
      return (suc > 0) ? true : false;
   }
   bool read(double &sal) {
      int suc;
      suc = fscanf(fptr, "%lf,", &sal);
      return (suc > 0) ? true : false;
   }
   
}