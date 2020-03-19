#include <iostream>
#include <string.h>

#include "UI.h"
#include "repo.h"
#include "domains.h"

void UI() {
	std::cout << "1. Adaugare\n";
	std::cout << "2. Afisare\n";
}

void add() {
	int day, sum;
	char string[] = "mancare";
	std::cout << "Day: ";
	std::cin >> day;
	std::cout << "Sum: ";
	std::cin >> sum;
	std::cout << "Type: ";
	Expense ex(day, sum, string);
}

