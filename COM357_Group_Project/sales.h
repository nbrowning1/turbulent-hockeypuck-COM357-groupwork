#include <iostream>
#include "product.h"

class sales :protected product {
protected:
	int invoice_no;
	int quantity;
	double total_price;
public:
	sales(){}

	sales(char pProduct_name[], int pProduct_code, double pPrice, int pInvoice,
		int pQuantity)
	{
		strcpy_s(product_name, pProduct_name);
		product_code = pProduct_code;
		price = pPrice;
		invoice_no = pInvoice;
		quantity = pQuantity;
		total_price = price*quantity;
	}

};