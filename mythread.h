#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : QThread
{
    Q_OBJECT
public:
    MyThread(const long long int first,
             const long long int end,
             QObject *parent = 0);
    void stop();

signals:
    void endIteration(const QString&);

protected:
    void run() Q_DECL_OVERRIDE ;

private:
    const long long int first;
    const long long int last;
    bool stopped;
};

#endif // MYTHREAD_H
