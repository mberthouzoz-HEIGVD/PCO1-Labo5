#include "waitingroom.h"

WaitingRoom::WaitingRoom(uint nbSeats) : NB_SEATS(nbSeats){

}

bool WaitingRoom::enter(MowCustomer* mowCustomer) {
    mutex.lock();

    if (nbTattooClientWaiting + nbMowClientWaiting == 0) {
        next = mowCustomer;
        CustomerWaiting.wakeOne();
        mutex.unlock();
    } else {
        nbMowClientWaiting++;
        MowWaiting.wait(&mutex);
        next = mowCustomer;
        nbMowClientWaiting--;
        mutex.unlock();
    }
}

bool WaitingRoom::enter(TattooCustomer* tattooCustomer) {
    mutex.lock();

    if (nbTattooClientWaiting + nbMowClientWaiting == 0) {
        next = tattooCustomer;
        CustomerWaiting.wakeOne();
        mutex.unlock();
    } else {
        nbTattooClientWaiting++;
        TattooWaiting.wait(&mutex);
        next = tattooCustomer;
        nbTattooClientWaiting--;
        mutex.unlock();
    }
}

void WaitingRoom::pickup(Barber* barber) {
    mutex.lock();

    if (nbTattooClientWaiting > 0) {
        TattooWaiting.wakeOne();
    } else if (nbMowClientWaiting > 0) {
        MowWaiting.wakeOne();
    } else {
        CustomerWaiting.wait(&mutex);
    }

    barber->serve(next);

    mutex.unlock();
}

