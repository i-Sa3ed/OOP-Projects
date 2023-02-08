#include "Phone.h"
#include <iostream>
using namespace std;

Phone::Phone()
{
    phone = "-";
    description = "freind";
    type = "mobile";
}

// setters (mutators):
void Phone::setPhone(string phone)
{
    this -> phone = phone;
}
void Phone::setDescription(string description)
{
    this->description = description;
}
void Phone::setType(string type)
{
    this->type = type;
}

// getter (accessor):
string Phone::getPhone()
{
    return phone;
}
