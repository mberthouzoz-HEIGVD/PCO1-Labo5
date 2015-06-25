#include "tattoocustomer.h"
#include "waitingroom.h"
#include "QDebug"

TattooCustomer::TattooCustomer(WaitingRoom* room) : Customer(room){
    name = "Client pour tatouage #" + count++;
}

void TattooCustomer::serve() {
    // la duree du tatouage
    unsigned int time_serve = (qrand() % (SERVE_MAX - SERVE_MIN + 1)) + SERVE_MIN;
    msleep(time_serve);
}

void TattooCustomer::run() {
    // attente en miliseconde
    msleep(durationWaiting);

    // boucle infinie
    forever {
        if (room->enter(this)) {
            msleep(durationWaiting);
        } else {
            // Attente de la moitié du temps
            msleep(durationWaiting / 2);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const TattooCustomer& c)
{
    out << c.name;
    return out;
}
