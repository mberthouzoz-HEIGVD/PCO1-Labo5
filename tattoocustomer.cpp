#include "tattoocustomer.h"
#include "waitingroom.h"
#include "QDebug"

TattooCustomer::TattooCustomer(WaitingRoom* room) : Customer(room){

}

void TattooCustomer::serve() {
    // la duree du tatouage
    unsigned int time_serve = (qrand() % (SERVE_MAX - SERVE_MIN + 1)) + SERVE_MIN;
    msleep(time_serve);
}

void TattooCustomer::run() {
    qDebug() << "Demarrage tattooCustomer" << metaObject()->className() << this << "\n";

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
