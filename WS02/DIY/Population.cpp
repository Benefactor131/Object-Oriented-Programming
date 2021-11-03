//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "File.h"
#include "Population.h"

using namespace std;

namespace sdds {

    int flag = 1;
    int sumOfPopulation = 0;
    int noOfPostalCodes;
    PostalCode* pc;

    void sort() {
        int i, j;
        PostalCode temp;
        for (i = noOfPostalCodes - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (pc[j].population > pc[j + 1].population) {
                    temp = pc[j];
                    pc[j] = pc[j + 1];
                    pc[j + 1] = temp;
                }
            }
        }
    }

    bool load(struct PostalCode& postalC) {
        bool ok = false;
        char code[128];
        int length;
        if (read(code) == true && read(postalC.population) == true) {
            length = strlen(code) + 1;
            postalC.postalCode = new char[length];
            strcpy(postalC.postalCode, code);
            sumOfPopulation += postalC.population;
            ok = true;
        }
        return ok;
    }

    bool load(const char* file) {
        bool ok = false;
        int i;
        if (openFile(file)) {
            noOfPostalCodes = noOfRecords();
            pc = new struct PostalCode[noOfPostalCodes];
            for (i = 0; i < noOfPostalCodes; i++)
            {
                load(pc[i]);
            }
            if (i == noOfPostalCodes)
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
            cout << "Could not open data file: " << file << endl;
        }
        return ok;
    }



    void display(struct PostalCode& postalCodes) {
        cout << flag << "- " << postalCodes.postalCode << ":  " << postalCodes.population << endl;
        flag++;
    }

    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < noOfPostalCodes; i++)
        {
            display(pc[i]);
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << sumOfPopulation << endl;
    }

    void deallocateMemory() {
        delete[] pc;
    }

}