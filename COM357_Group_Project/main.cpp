#include "invoice.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

vector<invoice*> invoice::invoices;

void displayMenu();
float invoice::grand_total_price = 0;
const string invoice::VALID_DATE_REGEX = "^(([1-9]|0[1-9]|1[0-9]|2[0-9]|3[0-1])\/([1-9]|0[1-9]|1[0-2])\/(200[0-9]|201[0-5]))$";

// TODO: 
	// 1) Fix price output so only 2d.p.
	// 2) Validation for negative numbers
	// 3) Validation for spaces in input / accept whole line input
void main() {
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	displayMenu();
}

void resetMenu() {
	cout << "- Press enter to return to menu ...";
	_getche();
	system("cls");
}

void displayMenu() {
	char choice;
	bool exit = false;
	do {
		cout << "--------------------------------------" << endl;
		cout << "Choices are:" << endl
			<< "A   -> Append Data" << endl
			<< "D   -> Display Invoice" << endl
			<< "T   -> Print Total Price" << endl
			<< "Q   -> Quit" << endl << endl
			<< "Select your choice: ";
		cin >> choice;

		switch (choice) {
		case 'A':
		case 'a': {
			invoice *newInvoice = new invoice();
			cout << endl << "New invoice added";
		}
			break;
		case 'D':
		case 'd': 
			invoice::display();
			break;
		case 'T':
		case 't': 
			invoice::printTotalPrice();
			break;
		case 'Q':
		case 'q':
			exit = true;
			break;
		default: 
			cout << endl << "Choice out of bounds";
		}

		if (!exit) {
			resetMenu();
		}
	} while (!exit);
}