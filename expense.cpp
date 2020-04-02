#include "expense.h"
#include <iostream>

Expense::Expense() {
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
}

Expense::Expense(const char* type, int day, int sum) {
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
	this->day = day;
	this->sum = sum;
}

Expense::Expense(const Expense& ex) {
	this->type = new char[strlen(ex.type) + 1];
	strcpy_s(this->type, strlen(ex.type) + 1, ex.type);
	this->day = ex.day;
	this->sum = ex.sum;
}

Expense::~Expense() {
	if (this->type)
		delete[] this->type;
	this->type = NULL;
}

int Expense::getDay() {
	return this->day;
}

int Expense::getSum() {
	return this->sum;
}

char* Expense::getType() {
	return this->type;
}


void Expense::setDay(int day) {
	this->day = day;
}

void Expense::setSum(int sum) {
	this->sum = sum;
}

void Expense::setType(const char* type) {
	if (this->type)
		delete[] this->type;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}



Expense& Expense::operator=(const Expense& ex) {
	if (this != &ex) {
		setType(ex.type);
		this->day = ex.day;
		this->sum = ex.sum;
	}
	return *this;

}

bool Expense::operator==(const Expense& ex) const {
	if (strcmp(this->type, ex.type) == 0 && this->day == ex.day && this->sum == ex.sum)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Expense& ex) {
	os << ex.day << ' ' << ex.sum << ' ' << ex.type << '\n';
	return os;
}

bool Expense::operator<(const Expense& ex) const {
	if (this->sum < ex.sum)
		return true;
	return false;
}

bool Expense::operator>(const Expense& ex) const {
	if (this->sum > ex.sum)
		return true;
	return false;
}



