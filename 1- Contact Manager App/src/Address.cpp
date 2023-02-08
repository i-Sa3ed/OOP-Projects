#include "Address.h"
#include <iostream>
using namespace std;


Address::Address()
{
    place = "-";
    description = "wonderful town!";
    type = "town";
}

//setters (mutators) :
void Address::setPlace(string newPlace)
{
    place = newPlace;
}
void Address::setDescription(string newDescription)
{
    description = newDescription;
}
void Address::setType(string newType)
{
    type = newType;
}

//getter (accessor)
string Address::getAddress()
{
    return place;
}
