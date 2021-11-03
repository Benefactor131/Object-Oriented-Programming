//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"

namespace sdds {
    class CalorieList {
        Product* m_products;
        int m_noOfProducts;
        int m_productsAdded;
        int totalCalories()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        // sets the CalorieList to accept the "size" number of Food Items. 
        // This function is called to prepare the CalorieList for accepting food items
        void init(int size);
        // Adds Food Items using their Name, Calorie count and time of consumption up to 
        // the number set in the init() function, returns true if successful.
        bool add(const char* item_name, int calories, int when);
        // Displays the report with food information and the total calorie consumed in the day
        // as shown in the report sample
        void display()const;
        // Releases all the memory used. After this function init() can be called for another
        // report;
        void deallocate();
    };
}

#endif // !SDDS_SUBJECT_H