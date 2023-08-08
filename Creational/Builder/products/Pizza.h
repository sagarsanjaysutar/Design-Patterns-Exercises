#ifndef PIZZA_H
#define PIZZA_H

#include "namespace.h"
#include <map>
#include <iostream>
using namespace std;

class Pizza
{
public:
    Pizza() : m_size(pizza::Size::Classic),
              m_crustType(pizza::Crust::Traditional),
              m_toppings({{pizza::Topping::NoTopping, getToppingName(pizza::Topping::NoTopping)}})
    {
        cout << "Pizza::Pizza(): Constructing base pizza " << this << endl;
    }
    ~Pizza()
    {
        cout << "Pizza::~Pizza() Destructing base pizza " << this << endl;
    }

    void addTopping(pizza::Topping topping)
    {
        std::multimap<pizza::Topping, std::string>::iterator toppingsItr = m_toppings.find(pizza::Topping::NoTopping);
        if (toppingsItr != m_toppings.end() && m_toppings.size() == 1)
        {
            m_toppings.clear();
        }
        m_toppings.insert({topping, getToppingName(topping)});
    }

    std::string getSizeName(pizza::Size value)
    {
        switch (value)
        {
        case pizza::Size::Small:
            return "Small";
        case pizza::Size::Classic:
            return "Classic";
        case pizza::Size::Large:
            return "Large";
        default:
            return "Unknown";
        }
    }

    std::string getCrustName(pizza::Crust value)
    {
        switch (value)
        {
        case pizza::Crust::Traditional:
            return "Traditional";
        case pizza::Crust::Stuffed:
            return "Stuffed";
        case pizza::Crust::DeepPan:
            return "DeepPan";
        case pizza::Crust::Thin:
            return "Thin";
        default:
            return "Unknown";
        }
    }

    std::string getToppingName(pizza::Topping value)
    {
        switch (value)
        {
        case pizza::Topping::NoTopping:
            return "NoTopping";
        case pizza::Topping::Cheese:
            return "Cheese";
        case pizza::Topping::Olives:
            return "Olives";
        case pizza::Topping::Mushrooms:
            return "Mushrooms";
        default:
            return "Unknown";
        }
    }

    void printPizza()
    {
        cout << "\n========= " << this << " Pizza Info ======= " << endl;
        cout << "Size: " << getSizeName(m_size) << endl;
        cout << "Crust: " << getCrustName(m_crustType) << endl;

        std::multimap<pizza::Topping, std::string>::iterator toppingsItr;
        for (toppingsItr = m_toppings.begin(); toppingsItr != m_toppings.end(); ++toppingsItr)
        {
            cout << "Topping: " << getToppingName(toppingsItr->first) << endl;
        }
        cout << "=====================\n"
             << endl;
    }

    pizza::Size m_size;
    pizza::Crust m_crustType;
    std::multimap<pizza::Topping, std::string> m_toppings;
};

#endif