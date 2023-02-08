#include "Contact.h"
#include "User.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>

using namespace std;

multimap <string, User> contactList; ///the main structure of the program.
// key : the full name.
// value : the users complete information.

Contact::Contact() //consturctor
{
    IDs = 0;
}

// add a user to the contact list :
void Contact::addUser()
{
    string first;
    cout << "first name : ";  cin >> first;

    string last;
    cout << "last name : ";  cin >> last;

    string full = first + " " + last;

    string gend;
    cout << "gender : ";  cin >> gend;

    string cit;
    cout << "city : ";  cin >> cit;

    User temp(first, last, gend, cit, IDs++);

    string address;
    cout << "address : ";  cin >> address;
    temp.setUserAddress(address, "-", "-");

    string mail;
    cout << "email : "; cin >> mail;
    temp.setUserEmail(mail, "-", "-");

    string phon;
    cout << "phone : "; cin >> phon;
    temp.setUserPhone(phon, "-", "-");

    contactList.insert({full, temp});
}

// to edit one of the user's attributes:
void Contact::editUser(string full) // get the para from the user in "main".
{
    auto it = contactList.find(full);
    if (it == contactList.end()) cout << "there is no such name in the contact list ..!";
    else {
        cout << "Choose from options : " << endl
            << setw(5) << "key" << setw(15) << "to edit" << endl << endl
            << setw(4) << 0 << setw(18) << "first name" << endl
            << setw(4) << 1 << setw(18) << "last name" << endl
            << setw(4) << 2 << setw(18) << "gender" << endl
            << setw(4) << 3 << setw(18) << "city" << endl
            << setw(4) << 4 << setw(18) << "address" << endl
            << setw(4) << 5 << setw(18) << "email" << endl
            << setw(4) << 6 << setw(18) << "phone number" << endl;

        int in;
        cin >> in;
        string toEdit;
        cout << "Enter the new value : ";
        cin >> toEdit;
        User temp = it->second;
        switch (in)
        {
            case 0 : temp.setFirstName(toEdit); break;
            case 1 : temp.setLastName(toEdit); break;
            case 2 : temp.setGender(toEdit); break;
            case 3 : temp.setCity(toEdit); break;
            case 4 :
                bool check;
                cout << "Do you want to enter Type and Description? (1/0)" << endl;
                cout << setw(5) << 1 << setw(5) << "yes" << endl
                    << setw(5) << 0 << setw(5) << "no";
                cin >> check;
                if (check) {
                    string newType;
                    cout << "type : ";  cin >> newType;
                    string newDes;
                    cout << "description : ";
                    cin.ignore();
                    getline(cin, newDes);
                    temp.setUserAddress(toEdit, newDes, newType);
                }
                else temp.setUserAddress(toEdit, "", "");
                break;
            case 5 :
                cout << "Do you want to add Type and Description? (1/0)" << endl;
                cout << setw(5) << 1 << setw(5) << "yes" << endl
                    << setw(5) << 0 << setw(5) << "no";
                cin >> check;
                if(check) {
                    string newType;
                    cout << "type : ";  cin >> newType;
                    string newDes;
                    cout << "description : ";
                    cin.ignore();
                    getline(cin, newDes);
                    temp.setUserEmail(toEdit, newDes, newType);
                }
                else temp.setUserEmail(toEdit, "", "");
                break;
            case 6 :
                cout << "Do you want to add Type and Description? (1/0)" << endl;
                cout << setw(5) << 1 << setw(5) << "yes" << endl
                    << setw(5) << 0 << setw(5) << "no";
                cin >> check;
                if(check) {
                    string newType;
                    cout << "type : ";  cin >> newType;
                    string newDes;
                    cout << "description : ";
                    cin.ignore();
                    getline(cin, newDes);
                    temp.setUserPhone(toEdit, newDes, newType);
                }
                else temp.setUserPhone(toEdit, "", "");
                break;
        }
        contactList.erase(full);
        full = temp.getFirstName() + " " + temp.getLastName();
        contactList.insert({full, temp});
    }
}

int Contact::countUser()
{
    return contactList.size();
}

// to search for a user using its name, and print its information:
void Contact::searchUser(int att) // get para from user in "main"
{
    bool found = 0;
    if (att == 0) { //for ID input.
        int input;
        cout << "Enter ID you want to search for : ";
        cin >> input;
        for (auto item : contactList)
        {
            if (item.second.getID() == input)
            {
                found = 1;
                cout << endl;
                item.second.showInfo();
                cout << endl << "\t====================\t" << endl;
            }
        }

        if (!found) cout << "not found any attribute called : " << input << endl;
    }
    else { //for another attributes.
        string input;

        if (att == 1) { //search for name.
            string full = "";
            cout << "Enter the first name for the user : ";
            cin >> input;
            full += input + " ";
            cout << "Enter the last name for the user : ";
            cin >> input;
            full += input;

            for (auto item : contactList)
            {
                if (item.first == full)
                {
                    found = 1;
                    cout << endl;
                    item.second.showInfo();
                    cout << endl << "\t====================\t" << endl;
                }
            }
            if (!found) cout << "not found any attribute called : " << full << endl;

        }
        else if (att == 2) //by gender
        {
            cout << "Enter the gender you want to search for : ";
            cin >> input;
            for (auto item : contactList)
            {
                if (item.second.getGender() == input)
                {
                    found = 1;
                    cout << endl;
                    item.second.showInfo();
                    cout << endl << "\t====================\t" << endl;
                }
            }
            if (!found) cout << "not found any attribute called : " << input << endl;
        }
        else if (att == 3) //by city
        {
            cout << "Enter the city you want to search for : ";
            cin >> input;
            for (auto item : contactList)
            {
                if (item.second.getCity() == input)
                {
                    found = 1;
                    cout << endl;
                    item.second.showInfo();
                    cout << endl << "\t====================\t" << endl;
                }
            }
            if (!found) cout << "not found any attribute called : " << input << endl;
        }
        else cout << "invalid input !!" << endl;
    }
}

void Contact::deleteUser(string full) // get para from user in main
{
    contactList.erase(full);
}

// show all the users in the list:
void Contact::showAll()
{
    for (auto item : contactList)
    {
        item.second.showInfo();
        cout << endl << "\t====================\t" << endl;
    }
}

// save the contact list to an external file:
void Contact::saveToFile()
{
    ofstream clearFile("Contact List.txt");
    //clearFile << "";
    for(auto item : contactList)
    {
        item.second.writeInfoOnFile();
    }
}
