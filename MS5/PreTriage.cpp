/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author	Bair Suimaliev
Revision History
-----------------------------------------------------------
Date      Reason
2020/04/09  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;

namespace sdds {
    void PreTriage::reg() {
        if (m_lineupSize == maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
            return;
        }
        else
        {
            int selection;
            int count = m_lineupSize;
            m_lineupSize++;
            m_pMenu >> selection;

            if (selection == 1)
            {
                m_lineup[count] = new CovidPatient();
            }
            else if (selection == 2)
            {
                m_lineup[count] = new TriagePatient();
            }
            else if (selection == 0)
            {
                return;
            }

            m_lineup[count]->setArrivalTime();
            m_lineup[count]->fileIO(false);

            cout << "Please enter patient information: " << endl;
            m_lineup[count]->read(cin);
            cout << "\n******************************************\n";
            cout << *m_lineup[count] << "Estimated Wait Time: " << getWaitTime(*m_lineup[count]) << endl;
            cout << "******************************************\n" << endl;
        }
    }

    void PreTriage::admit() {
        int selection;
        char type = '\0';
        m_pMenu >> selection;
        cout << endl;

        if (selection == 1)
        {
            type = 'C';
        }
        else if (selection == 2)
        {
            type = 'T';
        }
        else if (selection == 0)
        {
            return;
        }

        if (indexOfFirstInLine(type) == -1)
        {
            return;
        }

        int id = indexOfFirstInLine(type);

        cout << "******************************************\n";
        m_lineup[id]->fileIO(false);
        cout << "Calling for " << *m_lineup[id];
        cout << "******************************************\n" << endl;

        setAverageWaitTime(*m_lineup[id]);
        removePatientFromLineup(id);
    }

    const Time PreTriage::getWaitTime(const Patient& p)const {
        int count = 0;
        for (int i = 0; i < m_lineupSize && i > maxNoOfPatients; i++)
        {
            if (m_lineup[i] == &p)
            {
                count++;
            }
        }

        return count;
    }

    void PreTriage::setAverageWaitTime(const Patient& p) {
        Time CT;
        CT.setToNow();
        unsigned num = p.number();

        if (p.type() == 'C')
        {
            m_averCovidWait = ((CT - Time(p)) + (m_averCovidWait * (num - 1))) / num;
        }
        else if (p.type() == 'T')
        {
            m_averTriageWait = ((CT - Time(p)) + (m_averTriageWait * (num - 1))) / num;
        }
    }

    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        int i;
        for (i = 0; i < m_lineupSize; i++)
        {
            if (m_lineup[i]->type() == type)
            {
                break;
            }
        }

        if (i + 1 == m_lineupSize)
        {
            return -1;
        }

        return i;
    }

    void PreTriage::load() {
        char ch = '\0';
        Patient* pp = nullptr;
        ifstream file(m_dataFilename);
        ifstream fin(m_dataFilename);
        cout << "Loading data..." << endl;

        string str;
        getline(file, str, ',');
        file.close();
        if (strlen(str.c_str()) != 0) {
            fin >> m_averCovidWait;
            fin.ignore();
            fin >> m_averTriageWait;
            fin.ignore(256, '\n');
        }

        for (; fin && m_lineupSize != maxNoOfPatients; m_lineupSize++)
        {
            fin >> ch;
            fin.ignore();
            if (ch == 'C')
            {
                pp = new CovidPatient();
            }
            else if (ch == 'T')
            {
                pp = new TriagePatient();
            }
            if (pp) {
                pp->fileIO(true);
                fin >> *pp;
                pp->fileIO(false);
                m_lineup[m_lineupSize] = pp;
            }
        }

        if (m_lineupSize > 0 && m_lineupSize != maxNoOfPatients) {
            delete pp;
            m_lineupSize--;
        }

        if (!fin.eof())
        {
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
            cout << m_lineupSize << " Records imported...\n" << endl;
        }
        else if (m_lineupSize == 0)
        {
            cout << "No data or bad data file!\n" << endl;
        }
        else
        {
            cout << m_lineupSize << " Records imported...\n" << endl;
        }
    }

    PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
        m_averCovidWait = 15; 
        m_averTriageWait = 5;
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        load();
    }

    PreTriage::~PreTriage() {
        ofstream file(m_dataFilename);
        file << m_averCovidWait << "," << m_averTriageWait << endl;
        cout << "Saving Average Wait Times,\n   COVID Test: " << m_averCovidWait << "\n   Triage: " << m_averTriageWait << "\nSaving m_lineup..." << endl;

        for (int i = 0; i < m_lineupSize || i > maxNoOfPatients; i++)
        {
            m_lineup[i]->csvWrite(file);
            file << endl;
            cout << i + 1 << "- ";
            m_lineup[i]->csvWrite(cout);
            cout << endl;
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        cout << "done!" << endl;
    }

    void PreTriage::run(void) {
        int selection;
        m_appMenu >> selection;
        if (selection == 1)
        {
            reg();
            run();
        }
        else if (selection == 2)
        {
            admit();
            run();
        }
        else
        {
            return;
        }
    }
}