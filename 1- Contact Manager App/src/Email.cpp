#include "Email.h"
#include <iostream>
using namespace std;


Email::Email()
{
    email = "-";
    description = "friend";
    type = "gmail";
}

//setters(mutators) :
void Email::setEmail(string newEmail)
{
    email = newEmail;
}
void Email::setDescription(string newDescription)
{
    description = newDescription;
}
void Email::setType(string newType)
{
    type = newType;
}

//getter (accessor) :
string Email::getEmail()
{
    return email;
}
