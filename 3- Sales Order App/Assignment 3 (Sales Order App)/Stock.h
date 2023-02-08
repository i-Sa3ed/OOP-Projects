#pragma once
#include "Product.h"
#include <vector>
#include <iostream>
using namespace std;

class Stock
{
	int count;
	vector <Product> stockProducts;
	vector <int> productQuant;
public:
	Stock();
	bool findProduct(string _name);
	void addProduct(vector <Product>& products);
	void updateProduct(int _id);
	void deleteProduct(int _id);
	void updateQuant(int _id, int token);

	void setQuant(int _id, int new_quant);
	int getQuantity(int _id) const;
	int getProductsCount() const;
	double getProductPrice(int _id) const;
	Product* getProduct(int _id);

	friend ostream& operator<<(ostream& output, Stock& s);
};

