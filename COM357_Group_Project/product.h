#pragma once
#include <iostream>
#include <string>
using namespace std;

class product {

protected:
	string product_name;
	int product_code;
	float price;

public:
	product() {}

	product(string _product_name, int _product_code, float _price) 
		: product_name(_product_name), product_code(_product_code), price(_price) {}

	void display() {
		cout << "Price of " << product_name << ": £" << price;
	}
};