#include "User.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime> // used to get the current date and time.

using namespace std;

User::User() {}
User::User(string first, string last, string gen, string cit, int idd) //constructor
{
    firstName = first;
    lastName = last;
    gender = gen;
    city = cit;
    id = idd;

    time_t now = time(0);
    string temp = ctime(&now);
    addedDate = temp;
}

//setters//
//attributes:
void User::setFirstName(string newFirst)
{
    firstName = newFirst;
}
void User::setLastName(string newLast)
{
    lastName = newLast;
}
void User::setGender(string newGender)
{
    gender = newGender;
}
void User::setCity(string newCity)
{
    city = newCity;
}



//composed attributes setters:
void User::setUserAddress(string newAddress, string newDescripion = "", string newType = "")
{
    userAddress.setPlace(newAddress);
    userAddress.setDescription(newDescripion);
    userAddress.setType(newType);
}
void User::setUserEmail(string newEmail, string newDescription = "", string newType = "")
{
    userEmail.setEmail(newEmail);
    userEmail.setDescription(newDescription);
    userEmail.setType(newType);
}
void User::setUserPhone(string newPhone, string newDescription, string newType)
{
    userPhone.setPhone(newPhone);
    userPhone.setDescription(newDescription);
    userPhone.setType(newType);
}

//getters:
string User::getFirstName() const
{
    return firstName;
}
string User::getLastName() const
{
    return lastName;
}
int User::getID() const
{
    return id;
}
string User::getGender() const
{
    return gender;
}
string User::getCity() const
{
    return city;
}

// show the user's information:
void User::showInfo()
{
    cout << "id : " << id << endl
        << "first name : " << firstName << " | " << "last name : " << lastName << endl
        << "gender : " << gender << endl
        << "city : " << city << " | " << "address : " << userAddress.getAddress() << endl
        << "email : " << userEmail.getEmail() << " | " << "phone : " << userPhone.getPhone() << endl
        << "added date : " << addedDate << endl;
}

// type the informations of the user to an external file :
void User::writeInfoOnFile()
{
    string fileName = "Contact List.txt";

    fstream appOut(fileName, ios::app);
    appOut << "id : " << id << endl
        << "first name : " << firstName << " | " << "last name : " << lastName << endl
        << "gender : " << gender << endl
        << "city : " << city << " | " << "address : " << userAddress.getAddress() << endl
        << "email : " << userEmail.getEmail() << " | " << "phone : " << userPhone.getPhone() << endl
        << "added date : " << addedDate << endl;
        appOut << "====================" << endl;

}

// to search for an attribute of the user:
bool User::searchInfo()
{
    cout << "Choose from options : " << endl
        << setw(5) << "key" << setw(10) << "to look for" << endl
        << setw(5) << 0 << setw(10) << "id" << endl
        << setw(5) << 1 << setw(10) << "gender" << endl
        << setw(5) << 2 << setw(10) << "city" << endl
        << setw(5) << 3 << setw(10) << "address" << endl
        << setw(5) << 4 << setw(10) << "email" << endl
        << setw(5) << 5 << setw(10) << "phone" << endl;

        int in;
        cin >> in;
        switch(in)
        {
            case 0: return id? 1 : 0;
            case 1 : return gender == "-"? 0 : 1;
            case 2 : return city == "-"? 0 : 1;
            case 3 : return userAddress.getAddress() == "-"? 0 : 1;
            case 4 : return userEmail.getEmail() == "-"? 0 : 1;
            case 5 : return userPhone.getPhone() == "-"? 0 : 1;
            default : cout << "Invalid input ..!"; return 0;
        }

        //in main : if (search()) cout << "found" : cout << "not found"
}
