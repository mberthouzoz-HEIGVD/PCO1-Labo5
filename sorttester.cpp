#include "sorttester.h"

#include <QCoreApplication>
#include <iostream>

#include "bubblesort.h"
#include "bubblesortthreaded.h"
#include "time.h"

//#define TABSIZE 10000000
#define TABSIZE 10

SortTester::SortTester()
{
}

void SortTester::getSize() {
    std::cout << "Taille du tableau : ";
    std::cin >> tabSize;


    std::cout << "Nombre de thread : ";
    std::cin >> nbThread;
}

void SortTester::test()
{
    // Récupère la taille du tableau et le nombre de thread
    getSize();

    srand(time(0));

    // Initalise le tableau
    int *tab = new int[tabSize];

    for(qint64 i=0;i<tabSize;i++)
        tab[i] = rand();

    BubbleSort<int> sorter;

    sorter.sort(tab,tabSize);

    int initial = tab[0];
    bool error  = false;

    for(qint64 i=0;i<tabSize;i++)
    {
        if(initial > tab[i])
        {
            error = true;
            break;
        }
        initial = tab[i];
    }

    if(error)
       std::cout << "ERREUR " << std::endl;
    else
       std::cout << "Tri valide " << std::endl;

    delete[] tab;
}
