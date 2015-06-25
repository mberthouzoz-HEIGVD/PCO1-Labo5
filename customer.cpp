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

int Customer::count = 0;

std::ostream& operator<<(std::ostream& out, const Customer& c)
{
    out << c.name;
    return out;
}
