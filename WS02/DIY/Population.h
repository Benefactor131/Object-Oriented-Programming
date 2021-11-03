//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

    struct PostalCode {
        char* postalCode;
        int population;
    };

    void sort();
    bool load(struct PostalCode&);
    bool load(const char*);
    void display(struct PostalCode&);
    void display();
    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_