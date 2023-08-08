#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "products/iTransport.h"
#include <iostream>
using namespace std;

/** \brief The Creator class which holds the Factory Method.
 * Generally this class does not have implementation for the factory method.
 * The derived classes are responsible for implementing the factory method.
 */
class Logistics
{
public:
    Logistics() {}
    ~Logistics() {}

    /*!
     * \brief Factory Method
     */
    virtual iTransport *createTransport() { return nullptr; }
};

#endif
