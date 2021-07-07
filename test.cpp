#include <iostream>
#include <assert.h>

#include "test.h"
#include "expense.h"
#include "Repository.h"
#include "Service.h"

void test_domain() {
	Expense ex1("menaj", 1, 200);
	assert(strcmp(ex1.getType(), "menaj") == 0);
	assert(ex1.getDay() == 1);
	assert(ex1.getSum() == 200);

	Expense ex2;
	ex2.setType("intretinere");
	ex2.setDay(2);
	ex2.setSum(150);
	assert(strcmp(ex2.getType(), "intretinere") == 0);
	assert(ex2.getDay() == 2);
	assert(ex2.getSum() == 150);

	ex2 = ex1;
	assert(strcmp(ex1.getType(), "menaj") == 0);
	assert(ex1.getDay() == 1);
	assert(ex1.getSum() == 200);
}

void test_repository() {
	Repository storage1;
	Expense ex1("menaj", 1, 200);
	storage1.addElement(ex1);
	assert(storage1.getNumber() == 1);
	assert(storage1.getAll()[0] == ex1);
	storage1.deleteElement(ex1);
	assert(storage1.getNumber() == 0);
	Expense ex2("da", 1, 1);
	storage1.addElement(ex1);
	storage1.updateElement(ex1, ex2);
	assert(storage1.getAll()[0] == ex2);
	assert(storage1.findElement(ex2) == 1);
	storage1.deleteElement(ex2);
	assert(storage1.findElement(ex2) == -1);
	
}

void test_service() {
	Service storage;
	storage.addElement("mancare", 2, 200);
	assert(storage.getSize() == 1);
	storage.updateElement("mancare", 2, 200, "apa", 1, 200);
	Expense e("apa", 1, 200);
	assert(storage.getAll()[0] == e);
	assert(storage.findElement("apa", 1, 200) == 1);
	storage.deleteElement("apa", 1, 200);
	assert(storage.getSize() == 0);
}

void test_all() {
	test_domain();
	test_repository();
	test_service();
}