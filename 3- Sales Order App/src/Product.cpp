#include "Product.h"

Product::Product()
{
}

Product::Product(const Product& p)
{
	this->id = p.id;
	this->name = p.name;
	this->price = p.price;
}

Product::Product(int _id)
{
	id = _id;
	name = "product_name";
	price = 0;
}

void Product::setID(int newID)
{
	this->id = newID;
}

void Product::setName(string newName)
{
	this->name = newName;
}

void Product::setPrice(double newPrice)
{
	this->price = newPrice;
}

double Product::getPrice() const
{
	return price;
}

int Product::getID()
{
	return this->id;
}

string Product::getName()
{
	return name;
}

void Product::update()
{
	char in;
	cout << "do you want to update the product name? (y/n)\n";
	cin >> in;
	string newName;
	switch (in)
	{
	case 'y':
		cout << "Enter the new name: \n";
		cin >> newName;
		setName(newName);
		break;
	case 'n':
		break;
	default:
		cout << "invalid input!!\n";
	}

	cout << "do you want to update the product price? (y/n) \n";
	cin >> in;
	double newPrice;
	switch (in)
	{
	case 'y':
		cout << "Enter the new price: \n";
		cin >> newPrice;
		setPrice(newPrice);
		break;
	case 'n':
		break;
	default:
		cout << "invalid input!!\n";
	}
}

istream& operator>>(istream& input, Product& p)
{
	cout << "Enter the product name: ";
	input >> p.name;
	cout << "Enter the product price$: ";
	input >> p.price;

	return input;
}

ostream& operator<<(ostream& output, Product& p)
{
	output << "Product ID: " << p.id << '\t' << "Product Name: " << p.name << '\t' << "Product Price: " << p.price << endl;

	return output;
	// // O: insert return statement here
}