#include "invoice.h"

vector<invoice*> invoice::invoices;

void displayMenu();
float invoice::grand_total_price = 0;

void main() {
	displayMenu();
}

void displayMenu() {
	char choice;
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
		}
			break;
		case 'D':
		case 'd': 
			invoice::display();
			break;
		case 'T':
		case 't': 
			cout << "Total price: " << to_string(invoice::getTotalPrice()) << endl;
			break;
		case 'Q':
		case 'q':
			break;
		default: 
			cout << endl << "Choice out of bounds";
		}
	} while (choice != 'Q' || choice != 'q');
}