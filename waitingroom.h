#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include <QMutex>
#include <QWaitCondition>

#include "mowcustomer.h"
#include "tattoocustomer.h"
#include "barber.h"

// http://stackoverflow.com/questions/17898717/class-name-does-not-name-a-type
class Barber;

class WaitingRoom
{
private:
    const uint NB_SEATS;

    QMutex mutex;
    QWaitCondition MowWaiting;
    QWaitCondition TattooWaiting;
    QWaitCondition CustomerWaiting;

    uint nbMowClientWaiting = 0;
    uint nbTattooClientWaiting = 0;

    Customer* next;
public:
    WaitingRoom(uint nbSeats);

    bool enter(MowCustomer* mowCustomer);
    bool enter(TattooCustomer* TattooCustomer);

    void pickup(Barber* barber);
};

#endif // WAITINGROOM_H
