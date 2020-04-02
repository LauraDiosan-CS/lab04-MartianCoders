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
	void deleteElement(const char*, int, int); // Delete an Expense object from storage (In: position)
	void deleteByType(const char*);
	void deleteByDays(int, int);
	void updateElement(const char*, int, int, const char*, int, int); // Creates Expense object using input and update in storage by position (In: type, day, sum, position)
	int sumElements(const char*);
	vector<Expense> sortDay(int);
	vector<Expense> sortType(const char*);
	void filterType(const char*);
	void filterSums(const char*, string, int);
	Expense maxElement(int);

	/* Get's */
	int findElement(const char*, int, int); // Creates Expense object using input and returns position (In: type, day, sum | Out: position)
	vector<Expense> getAll(); // Returns pointer of storage (Out: storage pointer)
	int getSize(); // Returns size of storage (Out: number)


};