/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author	Bair Suimaliev
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/19  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#pragma once
#ifndef SDD_MENU_H
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
    class Menu {
        char* m_text; // holds the menu content dynamically
        int m_noOfSel;  // holds the number of options displayed in menu content
        void display()const;
    public:
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        operator bool()const;
        int& operator>>(int& Selection);
        // add safe copying logic
        Menu(const Menu& temp_obj);
        Menu& operator=(const Menu& temp_obj) = delete;
    };
};
#endif // SDD_MENU_H

