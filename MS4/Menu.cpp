/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;

namespace sdds {

    void Menu::display()const {
        cout << m_text << "\n0- Exit\n";
    }

    Menu::Menu(const char* MenuContent, int NoOfSelections) {
        m_noOfSel = NoOfSelections;
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);
    }

    Menu::~Menu() {
        delete[] m_text;
        m_text = nullptr;
    }

    Menu::Menu(const Menu& obj) {
        if (obj)
        {
            m_text = new char[strlen(obj.m_text) + 1];
            strcpy(m_text, obj.m_text);
            m_noOfSel = obj.m_noOfSel;
        }
    }

    Menu::operator bool()const {
        if (m_text != nullptr && m_noOfSel != 0)
        {
            return true;
        }
        return false;
    }

    int& Menu::operator>>(int& Selection) {
        display();
        Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");

        return Selection;
    }

};
