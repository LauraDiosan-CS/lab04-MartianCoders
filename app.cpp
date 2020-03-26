#include <iostream>
#include <crtdbg.h>
#include <stdio.h>

#include "test.h"

int main() {
	test_all();
	_CrtDumpMemoryLeaks();
}
