#include "OrderItem.h"

OrderItem::OrderItem(int _id, double sale_price, int quant, Product* ptr)
{
	id = _id;
	this->salePrice = sale_price;
	this->orderQuantity = quant;
	product = ptr;
}

double OrderItem::getPriceOI() { return (this->salePrice * this->orderQuantity); }

int OrderItem::getItemQuant()
{
	return orderQuantity;
}

Product* OrderItem::getProduct()
{
	return product;
}

OrderItem OrderItem::operator++(int)
{
	this->orderQuantity++;
	return *this;
}

OrderItem OrderItem::operator--(int)
{
	this->orderQuantity--;
	return *this;
}

OrderItem OrderItem::operator+=(int n)
{
	orderQuantity += n;
	return *this;
}

OrderItem OrderItem::operator-=(int n)
{
	orderQuantity -= n;
	return *this;
}

ostream& operator<<(ostream& output, OrderItem o)
{
	output << "Item ID: " << o.id << '\t' << "sale price = " << o.salePrice << '\t' << "order quantity = " << o.orderQuantity << endl
		<< *o.product;  
	return output;
	// // O: insert return statement here
}
