#include "mythread.h"

MyThread::MyThread(const long long int first
                   const long long int last,
                   QObject *parent) :
    firstPwd(first),
    lastPwd(last),
    stopped(false),
    QThread(parent)
{
}

MyThread::~MyThread()
{

}

