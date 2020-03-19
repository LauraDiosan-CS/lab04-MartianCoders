#include <iostream>

#include "domains.h"

Expense::Expense() {
	this->type = NULL;
	this->day = 0;
	this->sum = 0;
}

Expense::Expense(unsigned int day, unsigned int sum, char* type) {
	if (this->type) {
		delete[] this->type;
		this->type = NULL;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
	this->day = day;
	this->sum = sum;
}

Expense::~Expense() {
	if (this->type) {
		delete[] this->type;
		this->type = NULL;
	}
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

void Expense::setDay(unsigned int day) {
	this->day = day;
}

void Expense::setSum(unsigned int sum) {
	this->sum = sum;
}

void Expense::setType(char* type) {
	if (this->type) {
		delete[] this->type;
		this->type = NULL;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

Expense& Expense::operator=(const Expense& ex) {
	if (this->type) {
		delete[] this->type;
		this->type = NULL;
	}
	this->type = new char[strlen(ex.type) + 1];
	strcpy_s(this->type, strlen(ex.type) + 1, ex.type);
	this->sum = ex.sum;
	this->day = ex.day;
	return *this;
}
