#ifndef SHIP_H
#define SHIP_H

#include "iTransport.h"

/**
 * \brief Concrete product interface
 */
class Ship : public virtual iTransport
{
public:
    Ship()
    {
        cout << "Ship::Ship()" << endl;
    }
    ~Ship()
    {
        cout << "Ship::~Ship()" << endl;
    }
    void deliver() override
    {
        cout << "Ship::deliver()" << endl;
    };
};

#endif
