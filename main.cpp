/**
  * Michaël Berthouzoz & Eleonore Dagostino
  * 2015-06-25
  *
  * Implémentation un salon coiffure ou tattoo
  * à l'aide de moniteur
  *
  * Clients et barbiers sont des threads
  * La salle d'attente gère les clients qui sont
  * servis ou qui attendent.
  *
  * Le babier prend en priorité les clients à tatouer
  *
  * Test :
  * Nombre de client : 10
  * Nombre de siege  : 5
  *
  *
  */
#include "iostream"
#include "QDebug"
#include <QCoreApplication>

#include "waitingroom.h"
#include "customer.h"
#include "mowcustomer.h"
#include "tattoocustomer.h"
#include "barber.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int nbSeat;
    int nbCustomer;

    // Recupere les valeurs avec le controle de saisie
    do {
        cout << "Nombre de client [0 - 50]: ";
    } while (!(cin >> nbCustomer) || nbCustomer <= 0 || nbCustomer > 50);

    do {
        cout << endl << "Nombre de siege [0 - 50]: ";
    } while (!(cin >> nbSeat) || nbSeat <= 0 || nbSeat > 50);

    // Instance une salle d'attente avec le nombre de siege
    WaitingRoom room(nbSeat);

    // Instance les clients
    for (int i = 0; i < nbCustomer; i++) {
        if (qrand() % 2 == 0) {
            Customer *c = new MowCustomer(&room);
            c->setDurationWaiting(qrand() % 3000);
            c->start();
        } else {
            Customer *c = new TattooCustomer(&room);
            c->setDurationWaiting(qrand() % 20000);
            c->start();
        }
    }

    // Instance un barbier et lui attribue une salle
    Barber barber;
    barber.setRoom(&room);
    qDebug() << "Le barbier va travailler.";
    barber.start();

    return a.exec();
}
