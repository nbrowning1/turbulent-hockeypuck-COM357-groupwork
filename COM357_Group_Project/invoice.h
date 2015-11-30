#pragma once
#include <string>
#include <vector>
#include <limits>
#include <regex>
#include "sales.h"

class invoice :private sales {
	string seller_name;
	string invoice_date;
	static float grand_total_price;

	static vector<invoice*> invoices;

	static const int MAX_INT = numeric_limits<int>::max();
	static const string VALID_DATE_REGEX;

	static string getValidTextInput(string valName, int max_length) {
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

	static bool containsDecimal(float val) {
		if (val != (int)val) {
			return true;
		}
		return false;
	}

	static float getValidNumericInput(string valName, float max_size, bool only_whole_numbers) {
		float val;
		do {
			cout << "Enter " << valName << ": ";
			cin >> val;

			// validate that input is number
			if (!cin) {
				// clear cin buffer so rest of input is ignored
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid entry data - not a number" << endl;
			}
			// validate that input isn't too large
			else if (!validSize(val, max_size)) {
				cout << "Invalid entry data - too large" << endl;
			}
			// validate that input is whole number if applicable
			else if (only_whole_numbers && containsDecimal(val)) {
				cout << "Invalid entry data - not a whole number" << endl;
			}
			else {
				return val;
			}
		} while (true);
	}

	static int getValidFloatInput(string valName, float max_size) {
		return getValidNumericInput(valName, max_size, false);
	}

	static int getValidIntInput(string valName, int max_size) {
		return (int)getValidNumericInput(valName, (float)max_size, true);
	}

	static string getValidDateInput(string valName) {
		string val;
		do {
			cout << "Enter " << valName << ": ";
			cin >> val;
			if (regex_match(val, regex(VALID_DATE_REGEX))) {
				return val;
			}
			else {
				cout << "Invalid date" << endl;
			}
		} while (true);
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
		product_name = getValidTextInput("product name", 30);
		product_code = getValidIntInput("product code", MAX_INT);
		price = getValidFloatInput("product price", 1000.0f);
		invoice_no = getValidIntInput("invoice no.", MAX_INT);
		quantity = getValidIntInput("quantity sold", 100);
		seller_name = getValidTextInput("seller name", 15);
		invoice_date = getValidDateInput("invoice date");

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