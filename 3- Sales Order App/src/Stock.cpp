#include "Stock.h"

Stock::Stock()
{
	count = 0;
}

bool Stock::findProduct(string _name)
{
	bool found = 0;
	for (Product& p : stockProducts)
	{
		if (p.getName() == _name)
		{
			found = 1;
			break;
		}
	}
	return found;
}

void Stock::addProduct(vector <Product>& products)
{
	cout << "\tAll Products:\n";
	int i = 1;
	for (Product& p : products) // print all abstract products
	{
		cout << i++ << "- " << p;
	}
	cout << "\nChoose Product ID to add: ";
	int _id;  cin >> _id;

	if (_id < 0 || _id >= products.size()) // check if invalid id..
	{
		cout << "Invalid ID..\n";
		return;
	}

	string _name = products[_id].getName();
	if (findProduct(_name)) // check if the product already exist..
	{
		cout << "The product is already exist..\n";
		return;
	}


	Product temp = products[_id];
	temp.setID(this->count); // update the id to match the stock::count..
	stockProducts.push_back(temp);

	cout << "Enter the quantity of the product: ";
	int q;  cin >> q;
	productQuant.push_back(q);

	count++;
	cout << "ADDED~\n";
}

void Stock::updateProduct(int _id)
{
	if (_id < count) // in my interval.. 
		stockProducts[_id].update();
	else cout << "Not found such id..\n";
}

void Stock::deleteProduct(int _id)
{
	if (_id < count && _id >= 0)
	{
		stockProducts[count - 1].setID(_id);
		productQuant[count - 1] = productQuant[_id];

		count--;
		swap(stockProducts[_id], stockProducts[count]);
		swap(productQuant[_id], productQuant[count]);

		stockProducts.erase(stockProducts.end() - 1);
		productQuant.erase(productQuant.end() - 1);

		cout << "DELETED~\n";
	}
	else cout << "Not found such id..\n";
}

void Stock::setQuant(int _id, int new_quant)
{
	productQuant[_id] = new_quant;
}

void Stock::updateQuant(int _id, int token)
{
	productQuant[_id] -= token;
}

int Stock::getQuantity(int _id) const
{
	if (_id < count && _id >= 0)
	{
		return productQuant[_id];
	}
	else return 0;
}

int Stock::getProductsCount() const
{
	return count;
}

double Stock::getProductPrice(int _id) const
{
	return stockProducts[_id].getPrice();
}

Product* Stock::getProduct(int _id) 
{
	Product* temp = &stockProducts[_id];
	return temp;
}


ostream& operator<<(ostream& output, Stock& s)
{
	output << "\t-Stock Products-\n"
		<< "\t-------------------- \n";
	int i = 0;
	for (auto& item : s.stockProducts)
	{
		output << item;
		output << "Stock Quantity = " << s.productQuant[i] << endl;
		output << "---------------\n";
		i++;
	}

	return output;
	// // O: insert return statement here
}
