#include "waitingroom.h"
#include "QDebug"

WaitingRoom::WaitingRoom(uint nbSeats) : NB_SEATS(nbSeats){

}

bool WaitingRoom::enter(MowCustomer* mowCustomer) {
    mutex.lock();

    if (nbTattooClientWaiting + nbMowClientWaiting >= NB_SEATS) {
        // si la salle d'attente est déjà pleine, on ne peut pas entrer

        mutex.unlock();
        qDebug() << "Le client" << mowCustomer << "n'a pas eu de place.";
        return false;
    } else if (nbTattooClientWaiting + nbMowClientWaiting == 0) {
        // si personne n'est en attente, le client entrant est le suivant

        qDebug() << "Le client" << mowCustomer << "est le suivant.";
        next = mowCustomer;

        // on notifie le barbier comme quoi un client est arrivé
        CustomerWaiting.wakeOne();

        qDebug() << "Le client" << mowCustomer << "est servi.";
        mutex.unlock();
    } else {
        // sinon, il se met en attente

        qDebug() << "Le client" << mowCustomer << "est en attente.";
        nbMowClientWaiting++;

        // le client attend d'être appelé pour une tonte
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
        // si la salle d'attente est déjà pleine, on ne peut pas entrer

        mutex.unlock();
        qDebug() << "Le client" << tattooCustomer << "n'a pas eu de place.";
        return false;
    } else if (nbTattooClientWaiting + nbMowClientWaiting == 0) {
        // si personne n'est en attente, le client entrant est le suivant

        qDebug() << "Le client" << tattooCustomer << "est le suivant.";
        next = tattooCustomer;

        // on notifie le barbier comme quoi un client est arrivé
        CustomerWaiting.wakeOne();

        qDebug() << "Le client" << tattooCustomer << "est servi.";
        mutex.unlock();
    } else {
        // sinon, il se met en attente
        qDebug() << "Le client" << tattooCustomer << "est en attente.";
        nbTattooClientWaiting++;

        // le client attend d'être appelé pour un tatouage
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
        // si on a des tatouages, on les fait en priorité
        TattooWaiting.wakeOne();
    } else if (nbMowClientWaiting > 0) {
        // sinon on fait une tonte
        MowWaiting.wakeOne();
    } else {
        // si personne n'est là, on attend que quelqu'un arrive
        CustomerWaiting.wait(&mutex);
    }

    // on sert la prochaine personne
    barber->serve(next);

    mutex.unlock();
}

