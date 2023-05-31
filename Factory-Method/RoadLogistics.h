#ifndef RoadLogistics_H
#define RoadLogistics_H

#include "Logistics.h"
#include "products/Truck.h"

/** \brief Concrete Creator.
 * Responsible for implementing the factory method.
 */
class RoadLogistics : public Logistics
{
public:
    RoadLogistics()
    {
        cout << "RoadLogistics::RoadLogistics()" << endl;
    };

    ~RoadLogistics()
    {
        cout << "RoadLogistics::~RoadLogistics()" << endl;
    };

    /** \brief Factory method that returns a product.
     */
    iTransport *createTransport() override
    {
        cout << "RoadLogistics::createTransport(): Returning a Truck Object." << endl;
        return new Truck();
    };
};

#endif