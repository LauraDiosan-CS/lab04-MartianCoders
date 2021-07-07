#include "Repository.h"
#include "expense.h"

Repository::Repository() {
	this->file = NULL;
}

Repository::Repository(const char* file) {
	this->file = new char[strlen(file) + 1];
	strcpy_s(this->file, strlen(file) + 1, file);
	this->loadFile();
}

Repository::~Repository() {
	this->storage.clear();
}

void Repository::addElement(Expense ex) {

	this->storage.push_back(ex);
	this->saveFile();
}

void Repository::updateElement(Expense ex, Expense ex2) {
	std::vector<Expense>::iterator it;
	it = find(this->storage.begin(), this->storage.end(), ex);
	if (it != this->storage.end())
	{
		(*it).setDay(ex2.getDay());
		(*it).setSum(ex2.getSum());
		(*it).setType(ex2.getType());
		this->saveFile();
	}
}

void Repository::deleteElement(Expense ex) {
	std::vector<Expense>::iterator it;
	it = find(this->storage.begin(), this->storage.end(), ex);
	if (it != this->storage.end()) {
		this->storage.erase(it);
		this->saveFile();
	}
}

int Repository::getNumber() {
	return this->storage.size();
}

int Repository::findElement(Expense ex) {
	for (int i = 0; i < this->storage.size(); i++)
		if (this->storage[i] == ex)
			return i + 1;
	return -1;
}

vector<Expense> Repository::getAll() {
	return this->storage;
}

void Repository::loadFile() {
	if (this->file != NULL) {
		this->storage.clear();
		ifstream in(this->file);
		char* type = new char[20];
		int day, sum;
		while(!in.eof()){
			in >> day >> sum >> type;
			if (strlen(type) > 0)
			{
				Expense e(type, day, sum);
				this->addElement(e);
			}
		}
		delete[] type;
		type = NULL;
		in.close();
	}
}

void Repository::saveFile() {
	if (this->file != NULL) {
		ofstream out(this->file);
		for (int i = 0; i < this->storage.size(); i++)
			out << this->storage[i];
		out.close();
	}
}