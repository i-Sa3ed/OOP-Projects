#ifndef USER_H
#define USER_H
#include "Address.h"
#include "Email.h"
#include "Phone.h"
#include <string>

using namespace std;

class User
{
    public:
        User();
        User(string first, string last, string gen, string cit, int idd);
        bool searchInfo();
        void showInfo();
        void writeInfoOnFile();

        void setFirstName(string);
        void setLastName(string);
        void setGender(string);
        void setCity(string);

        void setUserAddress(string newAdd, string newDes, string newType);
        void setUserEmail(string newE, string newDes, string newType);
        void setUserPhone(string newPho, string newDes, string newType);

        string getFirstName() const;
        string getLastName() const;
        int getID() const;
        string getGender() const;
        string getCity() const;


    private:
        int id;
        string firstName, lastName, gender, city, addedDate;

        Address userAddress;
        Email userEmail;
        Phone userPhone;
};

#endif // USER_H
