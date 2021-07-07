#include <iostream>
#include <crtdbg.h>
#include <stdio.h>

#include "test.h"
#include "UI.h"
#include "Repository.h"
#include "Service.h"

int main() {
	test_all();

	Repository storage("Expenses.in");
	Service service(storage);
	UI ui(service);
	ui.runUI();
	
	_CrtDumpMemoryLeaks();
}
