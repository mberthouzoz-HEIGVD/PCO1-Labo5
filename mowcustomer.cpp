#include "mowcustomer.h"
#include "waitingroom.h"

MowCustomer::MowCustomer(WaitingRoom* room) : Customer(room) {

}

void MowCustomer::serve() {

}

void MowCustomer::run() {
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
