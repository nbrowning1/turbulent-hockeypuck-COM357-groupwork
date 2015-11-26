#pragma once
#include <string>
#include "sales.h"

class invoice :private sales {
	string seller_name;//char seller_name[20];
	string invoice_date;//char invoice_date[10];
	static float grand_total_price;

public:

	invoice() {
		cout << "Enter product name: ";
		cin >> product_name;
		cout << "Enter product code: ";
		cin >> product_code;
		cout << "Enter product price: ";
		cin >> price;
		cout << "Enter invoice no.: ";
		cin >> invoice_no;
		cout << "Enter quantity sold: ";
		cin >> quantity;
		cout << "Enter seller name: ";
		cin >> seller_name;
		cout << "Enter invoice date: ";
		cin >> invoice_date;

		total_price = price * quantity;
		grand_total_price += total_price;
	}

	invoice(string _product_name, int _product_code, float _price,
		int _invoice_no, int _quantity, string _seller_name, string _invoice_date)
		: sales(_product_name, _product_code, _price, _invoice_no, _quantity),
		seller_name(_seller_name), invoice_date(_invoice_date) {
		//strcpy_s(seller_name, _seller_name);
		//strcpy_s(invoice_date, _invoice_date);
	}

	void display() {
		// how can you display this stuff without keeping a vector of all objects created? 
			// for right now it'll just be member method
		cout << endl;
		cout << "'" << seller_name << "' company's invoice - Invoice no. " << invoice_no << endl;
		cout << "Date: " << invoice_date << endl;
		cout << "--------------------------------" << endl;
		cout << "Product name: " << product_name << endl;
		cout << "Product code: " << product_code << endl;
		cout << "Quantity (" << quantity << ") at price £" << to_string(price) << endl;
		cout << "--------------------------------" << endl;
		cout << "Total price: £" << to_string(total_price) << endl;
		cout << "--------------------------------" << endl << endl;

	}

	static float getTotalPrice() {
		return grand_total_price;
	}
};