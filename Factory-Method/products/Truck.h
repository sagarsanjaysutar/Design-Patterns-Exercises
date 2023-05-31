#ifndef TRUCK_H
#define TRUCK_H

#include "iTransport.h"

/**
 * \brief Concrete product interface
 */
class Truck : public virtual iTransport
{
public:
    Truck()
    {
        cout << "Truck::Truck()" << endl;
    }
    ~Truck()
    {
        cout << "Truck::~Truck()" << endl;
    }
    void deliver() override
    {
        cout << "Truck::deliver()" << endl;
    }
};

#endif