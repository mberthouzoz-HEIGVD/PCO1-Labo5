

#include "sorttester.h"
#include <iostream>
#include "QDebug"

int main(int argc, char *argv[])
{
    int size = 0;
    int nbThread = 0;

    std::cout << "Taille du tableau : ";
    std::cin >> size;


    std::cout << "Nombre de thread : ";
    std::cin >> nbThread;

    qDebug() << size << " " << nbThread;

    SortTester tester;
    tester.test();
}
