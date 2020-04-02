#include "Service.h"
#include "Repository.h"
#include "expense.h"
#include <algorithm>

Service::Service(){}

Service::Service(const Repository& storage) {
	this->storage = storage;
}

Service::~Service() {
}

void Service::addElement(const char* type, int day, int sum) {
	Expense e(type, day, sum);
	this->storage.addElement(e);
}

void Service::deleteElement(const char* type, int day, int sum) {
	Expense e(type, day, sum);
	this->storage.deleteElement(e);
}

void Service::deleteByType(const char* type)
{
	std::vector<Expense> storage = this->storage.getAll();
	for (int i = 0; i < storage.size(); i++)
		if (strcmp(storage[i].getType(), type) == 0)
			this->storage.deleteElement(storage[i]);
}

void Service::deleteByDays(int day1, int day2)
{
	if (day1 > day2)
		swap(day1, day2);
	std::vector<Expense> storage = this->storage.getAll();
	for (int i = 0; i < storage.size(); i++)
		if (storage[i].getDay() >= day1 && storage[i].getDay() <= day2)
			this->storage.deleteElement(storage[i]);
}

void Service::updateElement(const char* oType, int oDay, int oSum, const char* nType, int nDay, int nSum) {
	
	Expense e(oType, oDay, oSum);
	Expense e2(nType, nDay, nSum);
	this->storage.updateElement(e, e2);
}

int Service::sumElements(const char* type) {
	int sum = 0;
	std::vector<Expense> storage = this->storage.getAll();
	for (int i = 0; i < storage.size(); i++)
		if (strcmp(storage[i].getType(), type) == 0)
			sum = sum + storage[i].getSum();
	return sum;
}

Expense Service::maxElement(int day) {
	std::vector<Expense> storage = this->storage.getAll();
	Expense MAX("Invalid day", 0, 0);
	bool first = true;
	if (storage.size() > 0) {
		for (int i = 0; i < storage.size(); i++) {
			if (storage[i].getDay() == day) {
				if (first == true) {
					MAX = storage[i];
					first = false;
				}
				else if (storage[i].getSum() > MAX.getSum())
					MAX = storage[i];
			}
		}
		return MAX;
	}
}

vector<Expense> Service::sortDay(int day) {
	std::vector<Expense> storage = this->storage.getAll();
	std::vector<Expense> newStorage;

	for (int i = 0; i < storage.size(); i++)
		if(storage[i].getDay() == day)
			newStorage.push_back(storage[i]);

	std::sort(newStorage.begin(), newStorage.end(), [](Expense& ex1, Expense& ex2) { return ex1.getSum() > ex2.getSum(); });

	return newStorage;
}

vector<Expense> Service::sortType(const char* type) {
	std::vector<Expense> storage = this->storage.getAll();
	std::vector<Expense> newStorage;

	for (int i = 0; i < storage.size(); i++)
		if (strcmp(storage[i].getType(), type) == 0)
			newStorage.push_back(storage[i]);

	std::sort(newStorage.begin(), newStorage.end(), [](Expense& ex1, Expense& ex2) { return ex1.getSum() < ex2.getSum(); });

	return newStorage;
}

void Service::filterType(const char* type) {
	std::vector<Expense> storage = this->storage.getAll();
	
	for (int i = 0; i < storage.size(); i++)
		if (strcmp(storage[i].getType(), type) != 0)
			this->storage.deleteElement(storage[i]);
}

void Service::filterSums(const char* type, string sign, int sum) {
	std::vector<Expense> storage = this->storage.getAll();

	if (sign[0] == '<')
		for (int i = 0; i < storage.size(); i++)
			if ((strcmp(storage[i].getType(), type) != 0) || (storage[i].getSum() > sum))
				this->storage.deleteElement(storage[i]);
	if (sign[0] == '=')
		for (int i = 0; i < storage.size(); i++)
			if ((strcmp(storage[i].getType(), type) != 0) || (storage[i].getSum() != sum))
				this->storage.deleteElement(storage[i]);
	if (sign[0] == '>')
		for (int i = 0; i < storage.size(); i++)
			if ((strcmp(storage[i].getType(), type) != 0) || (storage[i].getSum() < sum))
				this->storage.deleteElement(storage[i]);
}

int Service::findElement(const char* type, int day, int sum) {
	Expense e(type, day, sum);
	return this->storage.findElement(e);
}

vector<Expense> Service::getAll() {
	return this->storage.getAll();
}

int Service::getSize() {
	return this->storage.getNumber();
}
