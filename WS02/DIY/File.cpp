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

   bool read(char* lt) {
       int suc;
       suc = fscanf(fptr, "%3s,", lt);
       return (suc > 0) ? true : false;
   }

   bool read(int& pop) {
       int suc;
       suc = fscanf(fptr, "%d\n", &pop);
       return (suc > 0) ? true : false;
   }
}