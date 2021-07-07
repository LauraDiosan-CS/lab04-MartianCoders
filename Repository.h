#pragma once
#include "expense.h"
#include <vector>

class Repository {
private:
	vector<Expense> storage;
	char* file;
public:
	/* Constructor & Destructor*/
	Repository(); // Default
	Repository(const char* file); // Set Repository after data files
	~Repository(); // Destructor

	/* Load & Save */
	void loadFile();
	void saveFile();

	/* Basic functions */
	void addElement(Expense); // Add an element in storage (In: Expense object)
	void updateElement(Expense, Expense); // Update an element from storage (In: Expense object, position)
	void deleteElement(Expense); // Delete an element from storage (In: position)

	/* Get's */
	int getNumber(); // Get number of elements (Out: number)
	int findElement(Expense); // Get position of an object/element given to search (In: Expense object | Out: position)
	vector<Expense> getAll(); // Get pointer of storage (Out: storage)
};