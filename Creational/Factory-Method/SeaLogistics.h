#ifndef SEALOGISTICS_H
#define SEALOGISTICS_H

#include "Logistics.h"
#include "products/Ship.h"

/** \brief Concrete Creator.
 * Responsible for implementing the factory method.
 */
class SeaLogistics : public Logistics
{
public:
    SeaLogistics(){};

    ~SeaLogistics()
    {
        cout << "SeaLogistics::~SeaLogistics()" << endl;
    };

    /** \brief Factory method that returns a product.
     */
    iTransport *createTransport() override
    {
        cout << "SeaLogistics::createTransport(): Returning a Ship Object." << endl;
        return new Ship();
    };
};

#endif