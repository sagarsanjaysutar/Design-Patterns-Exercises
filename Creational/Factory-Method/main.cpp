#include "Logistics.h"
#include "SeaLogistics.h"
#include "RoadLogistics.h"
#include "products/iTransport.h"

/**
 * \brief main.cpp is our client. It uses a creator class to generate a product using factory method.
 * Note that the client does not need to worry about what kind of product is returned and
 * product creation logic has been decoupled from the Creator class. It is inside factory implementation.
 */
int main()
{
    // Creator class
    RoadLogistics roadLogistics;
    SeaLogistics seaLogistics;

    // Generating product using Factory method.
    iTransport *roadTransport = roadLogistics.createTransport();
    iTransport *seaTransport = seaLogistics.createTransport();

    // The client can use the product without worrying about it's kind.
    roadTransport->deliver();
    seaTransport->deliver();

    // Pointers need to be deleted as they are created on heap,
    // as opposed to direct object created on stack whose lifetime is managed automatically.
    delete roadTransport;
    delete seaTransport;

    return 0;
}