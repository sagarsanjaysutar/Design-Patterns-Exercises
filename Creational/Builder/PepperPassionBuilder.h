#ifndef PEPPERPASSIONBUILDER_H
#define PEPPERPASSIONBUILDER_H

#include <iPizzaBuilder.h>
#include <Pizza.h>
#include <iostream>
using namespace std;

class PepperPassionBuilder : public virtual iPizzaBuilder
{
public:
    virtual void setSize(pizza::Size size) override
    {
        m_pizza.size = size;
    }

    virtual void setCrust(pizza::Crust crustType) override
    {
        m_pizza.crustType = crustType;
    }

    virtual void addTopping(pizza::Topping topping) override
    {
        m_pizza.toppings.push_back(topping);
    }

private:
    Pizza m_pizza;
};

#endif