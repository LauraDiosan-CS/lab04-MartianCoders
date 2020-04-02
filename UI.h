#pragma once
#include "Service.h"

class UI {
private:
	Service service;
	void showBaseMenu();
	void showHELP();
	void addUI(string);
	void updateUI(string);
	void deleteUI(string);
	void delete_tUI(string);
	void delete_zUI(string);
	void sumUI(string);
	void maxElementUI(string);
	void sortDay(string);
	void sortType(string);
	void filterType(string);
	void filterSums(string);
	void showAllUI();
	void show_tUI(string);
	void show_ttUI(string);
	void showBySign(const char*, string, int);
public:
	UI();
	UI(Service& service);
	void runUI();
};