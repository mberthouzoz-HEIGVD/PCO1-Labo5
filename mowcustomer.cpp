#include "mowcustomer.h"
#include "waitingroom.h"
#include "QDebug"

MowCustomer::MowCustomer(WaitingRoom* room) : Customer(room) {

}

void MowCustomer::serve() {
    qDebug() << "Serve" << metaObject()->className() << this;
    // la duree de la tonte
    unsigned int time_serve = (qrand() % (SERVE_MAX - SERVE_MIN + 1)) + SERVE_MIN;
    msleep(time_serve);
    qDebug() << "EndServe" << metaObject()->className() << this;
}

void MowCustomer::run() {
    qDebug() << "Demarrage mowCustomer" << metaObject()->className() << this << "\n";
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
