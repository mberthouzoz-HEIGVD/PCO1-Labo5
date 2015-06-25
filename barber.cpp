#include "barber.h"

Barber::Barber(QObject *parent) : QThread(parent), room(nullptr){

}

void Barber::setRoom(WaitingRoom* r) {
    room = r;
}

void Barber::serve(Customer* customer) {
    customer->serve();
}

WaitingRoom* Barber::getWaitingRoom() const {
    return room;
}

void Barber::setWaitingRoom(WaitingRoom* room) {
    this->room = room;
}

void Barber::run() {
    // test s'il a bien une salle attribuée
    Q_ASSERT(room);

    // boucle infinie
    forever {
        room->pickup(this);
    }
}

