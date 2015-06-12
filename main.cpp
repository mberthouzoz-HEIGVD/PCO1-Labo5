/**
  * Michaël Berthouzoz & Eleonore Dagostino
  * 2015-05-28
  *
  * Réaliser un algorithme de tri réparti en plusieurs tâches.
  *
  * On demande le nombre d'element et de thread voulus.
  * On partage le nombre d'element aux differents threads.
  * On applique un tri a bulle a chaque tableau et
  * on partage un ou deux element commun de chaque tableau.
  * On verifie si le resultat est bon si ce n est pas le cas
  * on recommence jusqu au resultat souhaite.
  *
  * Test
  * ---------------------------------------------------
  * Nbre Element   | Nbre Thread   |    Temps
  * ---------------------------------------------------
  * 10                     2            0.004
  * 1000                   2            0.17
  * 1000                   3            0.111
  * 1000                   4            0.113
  * 1000                   7            0.16
  * 5000                   3            9.202
  * 5000                   5            5.828
  * 5000                   7            4.55
  * 8888                   3           43.63
  * 10000                  2          109.994
  * 10000                  4           56.785
  * 10000                  7           32.687
  *
  * Pour 1000 elements on remaque qu'avec 2 threads
  * c'est plus rapide qu'avec 3 ou 4.
  * Pour 5000 et 10000, plus il y a de thread plus
  * c'est rapide.
  *
  * Les tests sont effectué sur un Lenovo Yoga 2 Pro
  * Windows 8.1 Professionnel 64 bits
  * Intel(R) Core(TM) i7-4500U CPU @ 1.80GHz 2.40GHz
  * 8 Go de Ram
  */
#include "iostream"
#include "QDebug"

#include "waitingroom.h"
#include "mowcustomer.h"
#include "tattoocustomer.h"
#include "barber.h"

using namespace std;

int main()
{
    int nbSeat;
    int nbCustomer;

    // Recupere les valeurs
    cout << "Nombre de siege: ";
    cin >> nbCustomer;

    cout << endl << "Nombre de client: ";
    cin >> nbSeat;

    WaitingRoom room(nbSeat);

    for (int i = 0; i < nbCustomer; i++) {
        qDebug() << qrand();
        /*if (qrand() == 0) {
            Customer *c = new MowClient(&room);
            c->setWaitingTime(qrand() % 3000);
            c->start();
        } else {
            Customer *c = new TattooClient(&room);
            c->setWaitingTime(qrand() % 20000);
            c->start();
        }*/
    }
/*
    Barber barber;
    barber.setRoom(&room);
    barber.start();*/

}
