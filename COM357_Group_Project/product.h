#pragma once
#include <iostream>
#include <string>
using namespace std;

class product {

protected:
	char product_name[30];
	int product_code;
	float price;

public:
	product() {}

	product(char _product_name[], int _product_code, float _price) 
		: product_code(_product_code), price(_price) {
		strcpy_s(product_name, _product_name);
	}

	void display() {
		cout << "Price of " << product_name << ": �" << price;
	}
};