#pragma once
#include "expense.h"

class Repository {
private:
	Expense storage[200];
	int number;
public:
	/* Constructor & Destructor*/
	Repository(); // Default 
	~Repository(); // Destructor

	/* Basic functions */
	void addElement(Expense); // Add an element in storage (In: Expense object)
	void updateElement(Expense, int); // Update an element from storage (In: Expense object, position)
	void deleteElement(int); // Delete an element from storage (In: position)

	/* Get's */
	int getNumber(); // Get number of elements (Out: number)
	int findElement(Expense); // Get position of an object/element given to search (In: Expense object | Out: position)
	Expense* getAll(); // Get pointer of storage (Out: storage)
};