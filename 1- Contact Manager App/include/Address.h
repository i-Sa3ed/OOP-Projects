#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
using namespace std;

class Address
{
    public:
        Address();
        void setPlace(string);
        void setType(string);
        void setDescription(string);

        string getAddress();


    private:
        string place, description, type;
        //take the description using 'getline' function.
};

#endif // ADDRESS_H
