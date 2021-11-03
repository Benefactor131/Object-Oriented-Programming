/* Citation and Sources...
Final Project Milestone 2
Module: utils
Filename: utils.cpp
Version 1.0
Author	Bair Suimaliev
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/12  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h

   int validInt(const char* str) {
       int count = 0;
       int len = strlen(str);
       for (int i = 0; i < len; i++)
       {
           if ((!isdigit(str[i]) && str[i] != '\n') || str[i] == ' ')
           {
               count++;
           }
       }
       return count;
   }

   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt) {
       bool ok = false;
       char str[10] = "";
       int len = 0;
       int numb = -1;

       if (prompt != nullptr)
       {
           cout << prompt;
       }

       while (!ok)
       {
           cin.getline(str, 10);
           len = strlen(str) + 1;

           if (validInt(str) == (len - 1))
           {
               cout << "Bad integer value, try again: ";
           }
           else if (validInt(str) < (len - 1) && validInt(str) != 0) {
               cout << "Enter only an integer, try again: ";
           }
           else {
               ok = true;
           }
       }
       
       numb = atoi(str);

       return numb;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
       bool ok = false;
       char str[10] = "";
       int len;
       int numb = -1;

       if (prompt != nullptr)
       {
           cout << prompt;
       }

       while (!ok)
       {
           cin.getline(str, 10);
           numb = atoi(str);
           len = strlen(str) + 1;

           if (errorMessage != nullptr && (numb < min || numb > max)) {
               cout << errorMessage;
               if (showRangeAtError) {
                   cout << '[' << min << " <= value <= " << max << "]: ";
               }
           }
           else if (validInt(str) == (len - 1))
           {
               cout << "Bad integer value, try again: ";
           }
           else if (validInt(str) < (len - 1) && validInt(str) != 0) {
               cout << "Enter only an integer, try again: ";
           }

           else {
               ok = true;
           }
       }

       return numb;
   }

   char* getcstr(const char* prompt, istream& istr, char delimiter) {
       string str;
       char* str1;

       if (prompt != nullptr)
       {
           cout << prompt;
       }

       getline(istr, str, delimiter);

       str1 = new char[strlen(str.c_str()) + 1];
       strcpy(str1, str.c_str());

       return str1;
   }

}