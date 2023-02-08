#include "Transaction.h"
#include "Stock.h"

Transaction::Transaction(int _id, Order& o)
{
	id = _id;
	order = o;
	transactionDate = __DATE__;
}

Transaction::Transaction(const Transaction& tr)
{
	this->id = tr.id;
	this->order = tr.order;
	this->transactionDate = tr.transactionDate;
}

void Transaction::addOrderItems(Stock& stock)
{
	order.addItems(stock);
}

void Transaction::updateOrderStatus(int status)
{
	order.updateStatus(status);
}

void Transaction::setOrderStatus(int status)
{
	order.setStatus(status);
}

double Transaction::getOrderTotal()
{
	return order.getTotal();
}

void Transaction::updateOrderQuantities(Stock& stock)
{
	order.updateItemQuant(stock);
}

void Transaction::payOrder(Payment& p)
{
	order.updateTotal(p.pay());
	cout << "PAID~\n";
}

ostream& operator<<(ostream& output, Transaction t)
{
	output << "transaction ID: " << t.id << '\t' << "Date: " << t.transactionDate << endl
		<< "Order Info: " << t.order << endl;
	return output;
	// // O: insert return statement here
}
