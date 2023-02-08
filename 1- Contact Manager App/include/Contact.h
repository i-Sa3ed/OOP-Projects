#ifndef CONTACT_H
#define CONTACT_H
#include "User.h"


class Contact
{
    public:
        Contact();
        void addUser();
        void editUser(string full);
        int countUser();
        void searchUser(int att);
        void deleteUser(string full);
        void showAll();
        void saveToFile();

    private:
        int IDs;
};

#endif // CONTACT_H
