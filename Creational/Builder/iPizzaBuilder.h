#ifndef IPIZZABUILDER_H
#define IPIZZABUILDER_H

#include "products/namespace.h"
#include "products/Pizza.h"

/** \brief This interface can be implemented by various Concrete Builders to customise
 * the pizza construction process and finally bake the Pizza.
 *
 * \note Although the Builders need to implement all these methods,
 * the client doesn't necessarily need to call all the steps to bake the Pizza.
 * The client can choose whichever "configs" i.e. "sequence of steps" they desire. *
 */
class iPizzaBuilder
{
public:
    virtual ~iPizzaBuilder(){};
    virtual void setSize(pizza::Size) = 0;
    virtual void setCrust(pizza::Crust) = 0;
    virtual void addTopping(pizza::Topping) = 0;

    /**
     * \brief Returns the final baked Pizza.
     */
    virtual Pizza *bakePizza() = 0;
    virtual void reset() = 0;
};

#endif