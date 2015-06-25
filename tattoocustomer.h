#ifndef TATTOOCUSTOMER_H
#define TATTOOCUSTOMER_H

#include "customer.h"

//http://stackoverflow.com/questions/17898717/class-name-does-not-name-a-type
class WaitingRoom;

class TattooCustomer : public Customer
{
    Q_OBJECT
protected:
    void run();

public:
    TattooCustomer(WaitingRoom* room);
    void serve();
private:
    static const int SERVE_MAX = 5000;
    static const int SERVE_MIN = 3000;
};

#endif // TATTOOCUSTOMER_H
