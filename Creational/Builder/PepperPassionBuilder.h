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
    }

    virtual void setSize(pizza::Size size) override
    {
        m_pizza->size = size;
    }

    virtual void setCrust(pizza::Crust crustType) override
    {
        m_pizza->crustType = crustType;
    }

    virtual void addTopping(pizza::Topping topping) override
    {
        m_pizza->addTopping(topping);
    }

    virtual Pizza *bakePizza() override
    {
        // Return the final Pizza and reset it.
        Pizza *tempPizza = m_pizza;
        cout << "0 " << m_pizza << " === " << tempPizza << endl;

        // <---problem line, this deletes the memory address
        // that was transfer from m_pizza to tempPizza,
        // thus we get seg fault when the client (main.cpp) use the returned object
        m_pizza = nullptr;
        cout << "1 " << m_pizza << " === " << tempPizza << endl;
        return tempPizza;
    }

private:
    // A pointer is used as we need to manage
    Pizza *m_pizza;
};

#endif