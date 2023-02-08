#ifndef EMAIL_H
#define EMAIL_H
#include <string>
using namespace std;

class Email
{
    public:
        Email();
        void setEmail(string);
        void setType(string);
        void setDescription(string);

        string getEmail();


    private:
        string email, description, type;
};

#endif // EMAIL_H
