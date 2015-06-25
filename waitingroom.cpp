#include "waitingroom.h"
#include "QDebug"

WaitingRoom::WaitingRoom(uint nbSeats) : NB_SEATS(nbSeats){

}

bool WaitingRoom::enter(MowCustomer* mowCustomer) {
    mutex.lock();

    if (nbTattooClientWaiting + nbMowClientWaiting >= NB_SEATS) {
        mutex.unlock();
        qDebug() << "Le client" << mowCustomer << "n'a pas eu de place.";
        return false;
    } else if (nbTattooClientWaiting + nbMowClientWaiting == 0) {
        next = mowCustomer;
        CustomerWaiting.wakeOne();
        qDebug() << "Le client" << mowCustomer << "est servi.";
        mutex.unlock();
    } else {
        nbMowClientWaiting++;
        MowWaiting.wait(&mutex);
        next = mowCustomer;
        nbMowClientWaiting--;
        qDebug() << "Le client" << mowCustomer << "est servi.";
        mutex.unlock();
    }

    return true;
}

bool WaitingRoom::enter(TattooCustomer* tattooCustomer) {
    mutex.lock();

    if (nbTattooClientWaiting + nbMowClientWaiting >= NB_SEATS) {
        mutex.unlock();
        qDebug() << "Le client" << tattooCustomer << "n'a pas eu de place.";
        return false;
    } else if (nbTattooClientWaiting + nbMowClientWaiting == 0) {
        next = tattooCustomer;
        CustomerWaiting.wakeOne();
        qDebug() << "Le client" << tattooCustomer << "est servi.";
        mutex.unlock();
    } else {
        nbTattooClientWaiting++;
        TattooWaiting.wait(&mutex);
        next = tattooCustomer;
        nbTattooClientWaiting--;
        qDebug() << "Le client" << tattooCustomer << "est servi.";
        mutex.unlock();
    }
    return true;
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

