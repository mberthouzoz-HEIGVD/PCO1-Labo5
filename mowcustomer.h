#ifndef MOWCUSTOMER_H
#define MOWCUSTOMER_H

#include "customer.h"

//http://stackoverflow.com/questions/17898717/class-name-does-not-name-a-type
class WaitingRoom;

class MowCustomer : public Customer
{
    Q_OBJECT
protected:
    void run();
public:
    MowCustomer(WaitingRoom* room);
    void serve();
};

#endif // MOWCUSTOMER_H
