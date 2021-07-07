#include "UI.h"

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

UI::UI(){}

UI::UI(Service& service) {
	this->service = service;
}

void UI::showBaseMenu() {
	std::cout << '\n';
	std::cout << "Type 'help' for commands info";
	std::cout << '\n';
}
void UI::showHELP() {
	std::cout << "\n";
	std::cout << "show | Afisare\n";
	std::cout << "show_t {tip} | Afisare dupa un anumit tip\n";
	std::cout << "show_t+ {tip} {semn} {suma} | Afisare tipuri dupa compararea pretului dat\n";
	std::cout << "----\n";
	std::cout << "add {zi} {suma} {tip} : Adaugare element\n";
	std::cout << "----\n";
	std::cout << "update {oldDay} {oldSum} {oldType} {newDay} {newSum} {newType}\n";
	std::cout << "----\n";
	std::cout << "delete {zi} {suma} {tip} | Sterge un anumit element\n";
	std::cout << "delete_z {zi} {zi} | Sterge intre 2 zile\n";
	std::cout << "delete_t {tip} | Sterge dupa un anumit tip\n";
	std::cout << "----\n";
	std::cout << "sum {tip} | Suma tuturor dupa un anumit tip\n";
	std::cout << "max {zi} | Ziua cu cele mai mari cheltuieli\n";
	std::cout << "sort {zi} | Afisare suma cheltuieli descrescator dupa zi\n";
	std::cout << "sort_t {tip} | Afisare suma cheltuieli crescator dupa tip\n";
	std::cout << "----\n";
	std::cout << "filter {tip} | Filtrare date dupa tip\n";
	std::cout << "filter_s {tip} {semn} {suma} | Filtrare date dupa tip respectand o suma\n";
	std::cout << "----\n";
	std::cout << "UNDO";
	std::cout << "\n";
}

void UI::showAllUI() {
	vector<Expense> storage = this->service.getAll();
	for (int i = 0; i < storage.size(); i++)
		std::cout << storage[i];
}

void UI::show_tUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	vector<Expense> storage = this->service.getAll();
	for (int i = 0; i < storage.size(); i++)
		if (strcmp(storage[i].getType(), type) == 0)
			std::cout << storage[i];
	delete[] type;
	type = NULL;

}

void UI::show_ttUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	string sign = cmd.substr(0, pos);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int sum = stoi(token);

	this->showBySign(type, sign, sum);
	delete[] type;
	type = NULL;
}

void UI::showBySign(const char* type, string sign, int sum) {
	std::vector<Expense> storage = this->service.getAll();
	if (sign[0] == '>') {
		for (int i = 0; i < storage.size(); i++)
			if ((strcmp(storage[i].getType(), type) == 0) && (storage[i].getSum() > sum))
				std::cout << storage[i];
	}
	else if (sign[0] == '<') {
		for (int i = 0; i < storage.size(); i++)
			if ((strcmp(storage[i].getType(), type) == 0) && (storage[i].getSum() < sum))
				std::cout << storage[i];
	}
	else if (sign[0] == '=') {
		for (int i = 0; i < storage.size(); i++)
			if ((strcmp(storage[i].getType(), type) == 0) && (storage[i].getSum() == sum))
				std::cout << storage[i];
	}
}

void UI::addUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int sum = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.addElement(type, day, sum);
	delete[] type;
	type = NULL;
}

void UI::updateUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int oDay = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int oSum = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* oType = new char[token.length() + 1];
	strcpy_s(oType, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int nDay = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int nSum = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* nType = new char[token.length() + 1];
	strcpy_s(nType, token.length() + 1, token.c_str());

	this->service.updateElement(oType, oDay, oSum, nType, nDay, nSum);
	delete[] oType;
	delete[] nType;
	oType = NULL;
	nType = NULL;
}

void UI::delete_tUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.deleteByType(type);
	delete[] type;
	type = NULL;
}

void UI::delete_zUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day1 = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day2 = stoi(token);

	this->service.deleteByDays(day1, day2);
}

void UI::deleteUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int sum = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.deleteElement(type, day, sum);
	delete[] type;
	type = NULL;
}

void UI::sumUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	std::cout << this->service.sumElements(type);

	delete[] type;
	type = NULL;
}

void UI::maxElementUI(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day = stoi(token);

	Expense element = this->service.maxElement(day);
	if (strcmp("Invalid day", element.getType()) == 0)
		std::cout << element.getType();
	else
		std::cout << element;
}

void UI::sortDay(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day = stoi(token);

	std::vector<Expense> sorted = this->service.sortDay(day);
	for (int i = 0; i < sorted.size(); i++)
		std::cout << sorted[i];
}

void UI::sortType(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	std::vector<Expense> sorted = this->service.sortType(type);
	for (int i = 0; i < sorted.size(); i++)
		std::cout << sorted[i];

	delete[] type;
	type = NULL;

}

void UI::filterType(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.filterType(type);

	delete[] type;
	type = NULL;
}

void UI::filterSums(string cmd) {
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	
	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	string sign = cmd.substr(0, pos);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int sum = stoi(token);

	this->service.filterSums(type, sign, sum);

	delete[] type;
	type = NULL;
}

void UI::runUI() {
	bool run = true;
	string cmd;
	while (run) {
		this->showBaseMenu();
		getline(cin, cmd);
		if (cmd.find("help") != string::npos)
			this->showHELP();

		if ((cmd.find("show_t+") != string::npos) && (cmd[5] == 't') && (cmd[6] == '+'))
			this->show_ttUI(cmd);
		else if ((cmd.find("show_t") != string::npos) && (cmd[5] == 't'))
			this->show_tUI(cmd);
		else if (cmd.find("show") != string::npos)
				this->showAllUI();

		if (cmd.find("add") != string::npos)
			this->addUI(cmd);

		if ((cmd.find("delete_t") != string::npos) && (cmd[7] == 't'))
			this->delete_tUI(cmd);
		else if ((cmd.find("delete_z") != string::npos) && (cmd[7] == 'z'))
			this->delete_zUI(cmd);
		else if (cmd.find("delete") != string::npos)
			this->deleteUI(cmd);

		if (cmd.find("max") != string::npos)
			this->maxElementUI(cmd);

		if ((cmd.find("sort_t") != string::npos) && (cmd[5] == 't'))
			this->sortType(cmd);
		else if (cmd.find("sort") != string::npos)
			this->sortDay(cmd);

		if (cmd.find("sum") != string::npos)
			this->sumUI(cmd);

		if ((cmd.find("filter_s") != string::npos) && (cmd[7] == 's'))
			this->filterSums(cmd);
		else if (cmd.find("filter") != string::npos)
			this->filterType(cmd);

		if (cmd.find("update") != string::npos)
			this->updateUI(cmd);
		if (cmd.find("exit") != string::npos)
			run = false;
	}
}