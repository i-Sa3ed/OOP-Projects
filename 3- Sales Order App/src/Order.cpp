#include "Order.h"
#include <cmath>
#include <time.h>
#include <string>
using namespace std;

void Order::addItems(Stock& stock)
{
	cout << "Enter the number of Items: ";
	int itemsNum;
	cin >> itemsNum;
	int stockSize = stock.getProductsCount();

	if (itemsNum > stockSize)
		cout << "Error.. input is greater than the number of products in the stock..\n";
	else
	{
		cout << endl;
		cout << stock; //overload..
		while (itemsNum--)
		{
			cout << "Choose the product ID: ";
			int _id;
			cin >> _id;
			if (_id < 0 || _id >= stockSize) // invalid
			{
				cout << "invalid id..\n\n";
				continue;
			}

			Product* tempProduct = stock.getProduct(_id);

			cout << "Enter the quantity: ";
			int _quant;
			cin >> _quant;
			if (_quant < 0 || _quant > stock.getQuantity(_id))
			{
				cout << "invalid quantity..\n";
				continue;
			}

			// if passed all of the above conditions: so it's a valid choice:
			stock.updateQuant(_id, _quant); // update stock quantity
			OrderItem tempOI(countOrderItems++, stock.getProductPrice(_id), _quant, tempProduct);
			total += tempOI.getPriceOI();
			orderItems.push_back(tempOI);
		}
	}
}

Order::Order()
{
	countOrderItems = 0;
	srand(time(0));
	number = (rand() % 1000000) + 1;

	date = __DATE__;

	os = orderStatus::NEW;
	total = 0;
}

Order::Order(Customer* ptr)
{
	countOrderItems = 0;
	srand(time(0));
	number = (rand() % 1000000) + 1;

	date = __DATE__;

	os = orderStatus::NEW;
	total = 0;
	customerPtr = ptr;
}

Order::Order(const Order& o)
{
	this->countOrderItems = o.countOrderItems;
	this->number = o.number;

	this->date = o.date;
	this->os = o.os;
	this->total = o.total;

	this->customerPtr = o.customerPtr;
}

void Order::printOrderItems()
{
	cout << "\t ~Order Items List~\n";
	for (OrderItem& item : orderItems)
		cout << item << "\n\t------------------\n";
}

void Order::updateStatus(int status)
{
	bool updated = 1;
	switch (status)
	{
	case 1:
		os = orderStatus::NEW;
		break;
	case 2:
		os = orderStatus::HOLD;
		break;
	case 3:
		os = orderStatus::PAID;
		break;
	case 4:
		os = orderStatus::CANCELLED;
		break;
	default:
		cout << "Invalid status..\n";
		updated = 0;
	}

	if (updated) cout << "UPDATED~\n";
}

void Order::setStatus(int status)
{
	switch (status)
	{
	case 1:
		os = orderStatus::NEW;
		break;
	case 2:
		os = orderStatus::HOLD;
		break;
	case 3:
		os = orderStatus::PAID;
		break;
	case 4:
		os = orderStatus::CANCELLED;
		break;
	default:
		cout << "Invalid status..\n";
	}

}

void Order::updateTotal(double paid_amount)
{
	total -= paid_amount;
	if (total == 0) setStatus(2); // paid
	else setStatus(1); // hold (partially paid)
}

double Order::getTotal()
{
	return total;
}

void Order::updateItemQuant(Stock& stock)
{
	cout << "\n\n";
	printOrderItems();
	cout << "Enter the ID of the item to update: ";
	int _id; cin >> _id;
	if (_id < 0 || _id >= countOrderItems) // invalid
	{
		cout << "Invalid ID..\n";
		return;
	}

	///
	total -= orderItems[_id].getPriceOI();
	unsigned int productID = orderItems[_id].getProduct()->getID();
	unsigned int stockQuantity = stock.getQuantity(productID);

	cout << "\tChoose: \n"
		<< "\t  1- Increase by 1\n"
		<< "\t  2- Decrease by 1\n"
		<< "\t  3- Increase by n\n"
		<< "\t  4- Decrease by n\n";

	int choice; cin >> choice;
	int n;
	switch (choice)
	{
	case 1:
		if (stockQuantity <= 0) // invalid..
		{
			cout << "There are no more pieces of this product :)\n";
		}
		else
		{
			orderItems[_id] ++;
			stock.updateQuant(productID, 1);
			cout << "UPDATED~\n";
		}
		break;
	case 2:
		if (orderItems[_id].getItemQuant() == 0) // invalid
			cout << "IMPOSSIBLE, The amount of this item is 0..\n";
		else
		{
			orderItems[_id] --;
			stock.updateQuant(productID, -1);
			cout << "UPDATED~\n";
		}
		break;
	case 3:
		cout << "Enter n: ";
		cin >> n;
		if (n < 0 || n > stockQuantity)
			cout << "Invalid Input..\n";
		else
		{
			orderItems[_id] += n;
			stock.updateQuant(productID, n);
			cout << "UPDATED~\n";
		}
		break;
	case 4:
		cout << "Enter n: ";
		cin >> n;
		if (n < 0 || n > orderItems[_id].getItemQuant())
			cout << "Invalid Input..\n";
		else
		{
			orderItems[_id] -= n;
			stock.updateQuant(productID, -n);
			cout << "UPDATED~\n";
		}
		break;
	default: cout << "Invalid Input..\n";
	}

	total += orderItems[_id].getPriceOI();
}

istream& operator>>(istream& input, Order& o)
{
	return input;
	// // O: insert return statement here
}

ostream& operator<<(ostream& output, Order& o)
{
	output << "Number: " << o.number << '\t' << "Date: " << o.date << '\t';
	output << "Status: ";
	if (o.os == orderStatus::NEW) output << "NEW\n";
	else if (o.os == orderStatus::HOLD) output << "HOLD\n";
	else if (o.os == orderStatus::PAID) output << "PAID\n";
	else output << "CANCELLED\n";

	output << "\t ~Order Items List~\n";
	output << "Number of Items = " << o.orderItems.size() << endl;
	for (OrderItem& item : o.orderItems)
		output << item;
	output << "\t((Total = " << o.total << "))" << endl;

	output << "\tCustomer Info:\n"
		<< *o.customerPtr << endl;

	return output;
	// // O: insert return statement here
}
