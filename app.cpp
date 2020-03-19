#include <iostream>

#include "tests.h"
#include "domains.h"
#include "repo.h"
#include "UI.h"

int main() {
	tests_Expense();
	tests_Repo();

	Repo rep;

	bool exist = true;
	while (exist != false)
	{
		UI();
		int command;
		std::cout << "Command:  ";
		std::cin >> command;
		switch (command)
		{
		case 1:
			break;
		case 2:
			break;
		default:
			exist = false;
		}
	}

	
}