#ifndef PEPPERPASSIONBUILDER_H
#define PEPPERPASSIONBUILDER_H

#include "iPizzaBuilder.h"
#include "products/Pizza.h"
#include <memory>
#include <iostream>
using namespace std;

class PepperPassionBuilder : public virtual iPizzaBuilder
{
public:
    PepperPassionBuilder() : m_pizza(new Pizza())
    {
        cout << "PepperPassionBuilder::PepperPassionBuilder()" << endl;
        setSize(pizza::Size::Large);
    }

    ~PepperPassionBuilder()
    {
        cout << "PepperPassionBuilder::~PepperPassionBuilder()" << endl;
        delete m_pizza;
    }

    virtual void setSize(pizza::Size size) override
    {
        m_pizza->m_size = size;
    }

    virtual void setCrust(pizza::Crust crustType) override
    {
        m_pizza->m_crustType = crustType;
    }

    virtual void addTopping(pizza::Topping topping) override
    {
        m_pizza->addTopping(topping);
    }

    virtual void reset() override
    {
        m_pizza = new Pizza();
    }

    virtual Pizza *bakePizza() override
    {
        // Return the final Pizza and reset the member pizza, in order to work with new one.
        Pizza *tempPizza = m_pizza;
        cout << "Returning baked pizza " << tempPizza << endl;
        reset();
        return tempPizza;
    }

private:
    Pizza *m_pizza;
};

#endif