#pragma once
#include "Product.h"

class OrderItem
{
	int id;
	double salePrice;
	int orderQuantity;
	Product* product;
public: 
	OrderItem(int _id, double sale_price = 0, int quant = 0, Product* ptr = NULL);
	double getPriceOI();
	int getItemQuant();
	Product* getProduct();

	OrderItem operator++(int);
	OrderItem operator--(int);
	OrderItem operator+=(int n);
	OrderItem operator-=(int n);
	friend ostream& operator<<(ostream& output, OrderItem o);
};

