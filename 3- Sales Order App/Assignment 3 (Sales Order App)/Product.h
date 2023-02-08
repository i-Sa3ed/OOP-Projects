#pragma once
#include <iostream>
using namespace std;

class Product
{
	int id;
	string name;
	double price;
public:
	Product(const Product& p);
	Product(int _id);
	void setID(int newID);
	void setName(string newName);
	void setPrice(double newPrice);

	double getPrice() const;
	int getID();
	string getName();

	void update();

	friend istream& operator>>(istream& input, Product& p);
	friend ostream& operator<<(ostream& output, Product& p);
};

