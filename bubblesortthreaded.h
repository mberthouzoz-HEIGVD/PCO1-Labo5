#ifndef BUBBLESORTTHREADED_H
#define BUBBLESORTTHREADED_H

#include "isort.h"
#include <QDebug>

template<typename T>
class BubbleSortThreaded : public ISort<T>
{
private:

public:

    BubbleSortThreaded() {}

    virtual void sort(T a[], qint64 size)
    {
        // Création des thread
        int nbrElement = tabSize / nbThread;

        for (i=0; i<nbThread; i++)
            {
                // Les paramètres 5 et 6 définissent la tranche de mot de passe que doit tester le thread
                currentThread = new MyThread(charset,
                                             salt,
                                             hash,
                                             nbChars,
                                             nbPwdTest * i,
                                             i == nbThreads - 1 ? nbToCompute : nbPwdTest * (i + 1) - 1,
                                             NULL);
                threadList.append(currentThread);

                // Connecte les signaux pour l'incrément du pourcentag et la fin de la recherche
                connect(currentThread,
                        SIGNAL(incrementPercentComputedThread(double)),
                        this,
                        SLOT(incrementPercentComputedTM(double)));

                connect(currentThread,
                        SIGNAL(endResearch(const QString&)),
                        this,
                        SLOT(endResearch(const QString&)));

                currentThread->start();
            }

            /* Attends la fin de chaque thread et libère la mémoire associée.
             * Durant l'attente, l'application est bloquée.
             */
            for (MyThread* currentThread: threadList)
            {
                currentThread->wait();
                delete currentThread;
            }
            /* Vide la liste de pointeurs de threads */
            threadList.clear();
    }
};

#endif // BUBBLESORTTHREADED_H
