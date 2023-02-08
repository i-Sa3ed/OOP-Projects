#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Payment.h"
#include <ctime>
#include <iostream>
using namespace std;

Payment::Payment(double _amount)
{
    time_t now = time(0);
    paidDate = ctime(&now);

    amount = _amount;
}

double Payment::pay()
{
    return amount;
}
