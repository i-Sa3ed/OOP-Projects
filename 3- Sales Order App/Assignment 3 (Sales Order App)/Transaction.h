#pragma once
#include "Order.h"
#include "Payment.h"

class Transaction
{
	int id;
	string transactionDate;
	Order order;
public:
	Transaction(int _id, Order& o);
	Transaction(const Transaction& tr);

	void addOrderItems(Stock& stock);
	void updateOrderStatus(int status);
	void updateOrderQuantities(Stock& stock);
	void payOrder(Payment& p);

	void setOrderStatus(int status);
	double getOrderTotal();

	friend ostream& operator<<(ostream& output, Transaction t);
};

