//Student Name: Bair Suimaliev
//Student ID: 159350198
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
	class Product {
		char foodName[31];
		int cal_num;
		int mealTime;
		void setName(const char* name);
		void printMealTime()const;
	public:
		void setEmpty();
		void set(const char* name, int cals, int mealTime);
		void display()const;
		bool isValid()const;
		int caloriesCount()const;
	};
}

#endif // !SDDS_SUBJECT_H