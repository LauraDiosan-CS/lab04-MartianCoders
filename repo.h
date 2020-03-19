#pragma once
#include "domains.h"

class Repo {
private:
	Expense expenses[200];
	unsigned int number;
public:
	Repo();
	~Repo();

	int getNumber();
	void addExpense(Expense ex);
	Expense* getAll();
};