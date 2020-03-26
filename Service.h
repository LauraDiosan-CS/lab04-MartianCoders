#pragma once
#include "Repository.h"
#include "expense.h"

class Service {
private:
	Repository storage;
public:
	/* Constructor & Destructor */
	Service(); // Default
	Service(const Repository&); // With Repository object (In: Repository object)
	~Service(); // Destructor

	/* Basic functions */
	void addElement(const char*, int, int); // Creates Expense object using input and add in storage (In: type, day, sum)
	void deleteElement(int); // Delete an Expense object from storage (In: position)
	void updateElement(const char*, int, int, int); // Creates Expense object using input and update in storage by position (In: type, day, sum, position)

	/* Get's */
	int findElement(const char*, int, int); // Creates Expense object using input and returns position (In: type, day, sum | Out: position)
	Expense* getAll(); // Returns pointer of storage (Out: storage pointer)
	int getSize(); // Returns size of storage (Out: number)



};