#include "tattoocustomer.h"
#include "waitingroom.h"

TattooCustomer::TattooCustomer(WaitingRoom* room) : Customer(room){

}

void TattooCustomer::serve() {

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
