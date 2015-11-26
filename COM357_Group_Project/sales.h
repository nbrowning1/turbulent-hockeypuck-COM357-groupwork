#pragma once
#include "product.h"

class sales :protected product {

protected:
	int invoice_no;
	int quantity;
	float total_price;

public:
	sales() {}

	sales(string _product_name, int _product_code, float _price,
		int _invoice_no, int _quantity)
		: product(_product_name, _product_code, _price),
		invoice_no(_invoice_no), quantity(_quantity) {

		total_price = _price * _quantity;
	}
};