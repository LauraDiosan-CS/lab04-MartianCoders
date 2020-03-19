#pragma once

#ifndef EXPENSE_H
#define EXPENSE_H

class Expense {
private:
	unsigned int day;
	unsigned int sum;
	char* type;
public:
	Expense();
	Expense(unsigned int day, unsigned int sum, char *type);
	~Expense();

	int getDay();
	int getSum();
	char* getType();

	void setDay(unsigned int day);
	void setSum(unsigned int sum);
	void setType(char* type);

	Expense& operator=(const Expense& ex);

};

#endif // EXPENSE