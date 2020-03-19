#include <iostream>
#include <assert.h>

#include "domains.h"
#include "repo.h"

void tests_Expense() {

	Expense ex1;
	char* type = new char[100];
	strcpy_s(type, sizeof "menaj", "menaj");

	ex1.setDay(3);
	ex1.setSum(200);
	ex1.setType(type);
	assert(ex1.getDay() == 3);
	assert(ex1.getSum() == 200);
	

	Expense ex2(5, 500, type);
	assert(ex2.getDay() == 5);
	assert(ex2.getSum() == 500);
	
	ex1 = ex2;
	assert(ex1.getDay() == 5);
	assert(ex1.getSum() == 500);
	delete[] type;
	
}

void tests_Repo() {
	Repo rep;
	char* type = new char[100];
	strcpy_s(type, sizeof "menaj", "menaj");
	Expense ex3;
	ex3.setDay(3);
	ex3.setSum(200);
	ex3.setType(type);

	delete[] type;
}