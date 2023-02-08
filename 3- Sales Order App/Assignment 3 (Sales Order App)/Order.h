#pragma once

#include "OrderItem.h"
#include "Stock.h"
#include "Customer.h"
#include <vector>

enum class orderStatus { NEW, HOLD, PAID, CANCELLED };

class Order
{
	int countOrderItems;
	orderStatus os;
	vector <OrderItem> orderItems;
	int number;
	double total;
	string date;
	Customer* customerPtr;

public:
	Order();
	Order(Customer* ptr);
	Order(const Order& o);

	void addItems(Stock& stock);
	void printOrderItems();

	void updateStatus(int status);
	void setStatus(int status);

	void updateItemQuant(Stock& stock);

	void updateTotal(double paid_amount);
	double getTotal();

	friend istream& operator>>(istream& input, Order& o);
	friend ostream& operator<<(ostream& output , Order& o);
};

