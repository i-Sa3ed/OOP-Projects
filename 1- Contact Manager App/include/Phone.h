#ifndef PHONE_H
#define PHONE_H
#include <string>
using namespace std;


class Phone
{
    public:
        Phone ();
        void setPhone(string);
        void setType(string);
        void setDescription(string);

        string getPhone();


    private:
        string phone, description, type;
};

#endif // PHONE_H
