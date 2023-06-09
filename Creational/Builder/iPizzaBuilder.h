#ifndef IPIZZABUILDER_H
#define IPIZZABUILDER_H

#include "namespace.h"

class iPizzaBuilder
{
public:
    virtual void setSize(pizza::Size) = 0;
    virtual void setCrust(pizza::Crust) = 0;
    virtual void addTopping(pizza::Topping) = 0;
};

#endif