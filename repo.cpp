#include <iostream>

#include "repo.h"

Repo::Repo() {
	this->number = 0;
}

Repo::~Repo() {
	this->number = 0;
}

int Repo::getNumber() {
	return this->number;
}

void Repo::addExpense(Expense ex) {
	this->expenses[this->number++] = ex;
}
Expense* Repo::getAll() {
	return this->expenses;
}