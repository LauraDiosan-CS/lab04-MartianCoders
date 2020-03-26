#include "Repository.h"
#include "expense.h"

Repository::Repository() {
	this->number = 0;
}

Repository::~Repository() {
	this->number = 0;
}

void Repository::addElement(Expense ex) {
	this->storage[this->number++] = ex;
}

void Repository::updateElement(Expense ex, int pos) {
	if (pos - 1 >= 0 && pos - 1 < this->number)
		this->storage[pos - 1] = ex;
}

void Repository::deleteElement(int pos) {
	if (pos - 1 >= 0 && pos - 1 < this->number)
	{
		for (int i = pos; i < this->number; i++)
			this->storage[i - 1] = this->storage[i];
	}
	this->number--;
}

int Repository::getNumber() {
	return this->number;
}

int Repository::findElement(Expense ex) {
	for (int i = 0; i < this->number; i++)
		if (this->storage[i] == ex)
			return i + 1;
	return -1;
}

Expense* Repository::getAll() {
	return this->storage;
}
