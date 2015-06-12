#include "customer.h"

Customer::Customer(WaitingRoom *room) :
    room(room)
{
}

ulong Customer::getDurationWaiting() const
{
    return durationWaiting;
}

void Customer::setDurationWaiting(ulong duration)
{
    durationWaiting = duration;
}
