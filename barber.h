#ifndef BARBER_H
#define BARBER_H

#include "QThread"

#include "waitingroom.h"
#include "customer.h"

//http://stackoverflow.com/questions/17898717/class-name-does-not-name-a-type
class WaitingRoom;
class Customer;

class Barber : public QThread
{
    Q_OBJECT
private:
    WaitingRoom* room;
public:
    Barber();
    Barber(WaitingRoom* room);

    void setRoom(WaitingRoom* room);
    void serve(Customer* customer);
    WaitingRoom* getWaitingRoom() const;
    void setWaitingRoom(WaitingRoom* room);
public slots:
    void run() Q_DECL_OVERRIDE;
};

#endif // BARBER_H
