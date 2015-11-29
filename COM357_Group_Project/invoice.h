#pragma once
#include <string>
#include <vector>
#include <limits>
#include "sales.h"

class invoice :private sales {
	string seller_name;
	string invoice_date;
	static float grand_total_price;

	static vector<invoice*> invoices;

	static const int MAX_INT = numeric_limits<int>::max();

	static string getValidInput(string valName, int max_length) {
		string val;
		do {
			cout << "Enter " << valName << ": ";
			cin >> val;
			if (validLength(val, max_length)) {
				return val;
			}
			else {
				cout << "Invalid entry length" << endl;
			}
		} while (true);
	}

	static float getValidInput(string valName, float max_size) {
		float val;
		do {
			cout << "Enter " << valName << ": ";
			cin >> val;
			if (!cin) {
				// clear cin buffer so rest of input is ignored
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid entry data" << endl;
			}
			else if (validSize(val, max_size)) {
				return val;
			}
			else {
				cout << "Invalid entry size" << endl;
			}
		} while (true);
	}

	static int getValidIntInput(string valName, int max_size) {
		return (int)getValidInput(valName, (float)max_size);
	}

	static bool validLength(string val, int max_length) {
		return val.length() <= max_length;
	}

	static bool validSize(float val, float max_size) {
		return val <= max_size;
	}

	void displayInvoice() {
		cout << "--------------------------------" << endl;
		cout << "'" << seller_name << "' company's invoice -- Invoice no. " << invoice_no << endl;
		cout << "Date:          | " << invoice_date << endl;
		cout << "Product name:  | " << product_name << endl;
		cout << "Product code:  | " << product_code << endl;
		cout << "Quantity (" << quantity << ") at price £" << to_string(price) << endl;
		cout << "-> £" << to_string(total_price) << endl;
		cout << "--------------------------------" << endl;
	}

public:

	invoice() {
		product_name = getValidInput("product name", 30);
		product_code = getValidIntInput("product code", MAX_INT);
		price = getValidInput("product price", 1000.0f);
		invoice_no = getValidIntInput("invoice no.", MAX_INT);
		quantity = getValidIntInput("quantity sold", 100);
		seller_name = getValidInput("seller name", 15);
		invoice_date = getValidInput("invoice date", 10);

		total_price = price * quantity;
		grand_total_price += total_price;
		invoices.push_back(this);
	}

	invoice(string _product_name, int _product_code, float _price,
		int _invoice_no, int _quantity, string _seller_name, string _invoice_date)
		: sales(_product_name, _product_code, _price, _invoice_no, _quantity),
		seller_name(_seller_name), invoice_date(_invoice_date) {}

	static void display() {
		if (invoices.empty()) {
			cout << "No invoices added" << endl;
		}
		else {
			for (invoice* inv : invoices) {
				inv->displayInvoice();
			}
			printTotalPrice();
		}
	}

	static void printTotalPrice() {
		cout << "--------------------------------" << endl;
		cout << "Total price: £" << to_string(grand_total_price) << endl;
		cout << "--------------------------------" << endl;
	}
};