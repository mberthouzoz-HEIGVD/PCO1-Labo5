#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "QThread"

// http://30minparjour.la-bnbox.fr/2012/qt-undefined-reference-to-vtable-for
//http://stackoverflow.com/questions/17898717/class-name-does-not-name-a-type
class WaitingRoom;

class Customer : public QThread
{
    Q_OBJECT
protected:
    WaitingRoom* room;
    ulong durationWaiting;
public:
    Customer(WaitingRoom* room);
    virtual void serve() = 0;
    ulong getDurationWaiting() const;
    void setDurationWaiting(ulong duration);

public slots:
    void run() Q_DECL_OVERRIDE = 0;
};

#endif // CUSTOMER_H
