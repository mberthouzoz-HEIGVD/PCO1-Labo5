#include "barber.h"

Barber::Barber() : room(nullptr){

}

Barber::Barber(WaitingRoom* room) : room(room){

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

