#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Expense {
private:
	int day;
	int sum;
	char* type;
public:
	/* Constructors & Destructor */
	Expense(); // Default
	Expense(const char*, int, int); // Given data (type, day, sum)
	Expense(const Expense&); // Given another Expense object
	~Expense(); // Destructor

	/* Get's */
	int getDay(); // Get day (Out: day)
	int getSum(); // Get sum (Out: sum)
	char* getType(); // Get type (Out: type)

	/* Set's */
	void setDay(int); // Set day (In: day)
	void setSum(int); // Set sum (In: sum)
	void setType(const char*); // Set type (In: type)

	Expense& operator=(const Expense&);

	bool operator<(const Expense&) const;
	bool operator>(const Expense&) const;
	bool operator==(const Expense&) const;
	bool operator!=(const Expense&) const;

	friend ostream& operator<<(ostream&, const Expense&);
	friend istream& operator>>(istream&, Expense&);

};