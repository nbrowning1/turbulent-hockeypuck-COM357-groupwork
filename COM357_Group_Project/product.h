#include <iostream>
#include <string>
using namespace std;

class product
{
protected:

	char product_name[30];
	int product_code;
	double price;

	product::product(char pproduct_name[30], int pproduct_code, double pprice){

		strcpy_s(product_name, pproduct_name);
		product_code = pproduct_code;
		price = pprice;
	}

	product::product(){
	}

	void display(){
		cout << "Product name: " << product_name << endl;
		cout << "Product price: " << price << endl;
		cout << "Product code: " << product_code << endl;
	}

};