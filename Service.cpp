#include "Service.h"
#include "Repository.h"
#include "expense.h"

Service::Service(){}

Service::Service(const Repository& storage) {
	this->storage = storage;
}

Service::~Service() {}

void Service::addElement(const char* type, int day, int sum) {
	Expense e(type, day, sum);
	this->storage.addElement(e);
}

void Service::deleteElement(int pos) {
	this->storage.deleteElement(pos);
}

void Service::updateElement(const char* type, int day, int sum, int pos) {
	Expense e(type, day, sum);
	this->storage.updateElement(e, pos);
}

int Service::findElement(const char* type, int day, int sum) {
	Expense e(type, day, sum);
	return this->storage.findElement(e);
}

Expense* Service::getAll() {
	return this->storage.getAll();
}

int Service::getSize() {
	return this->storage.getNumber();
}