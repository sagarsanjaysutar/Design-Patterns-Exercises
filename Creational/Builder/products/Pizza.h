#ifndef PIZZA_H
#define PIZZA_H

#include "namespace.h"
#include <map>
#include <iostream>
using namespace std;

class Pizza
{
public:
    Pizza() : size(pizza::Size::Classic),
              crustType(pizza::Crust::Traditional),
              toppings({{pizza::Topping::NoTopping, getToppingName(pizza::Topping::NoTopping)}})
    {
        cout << "Pizza::Pizza() " << this << endl;
    }
    ~Pizza()
    {
        cout << "Pizza::~Pizza()" << this << endl;
    }

    void addTopping(pizza::Topping topping)
    {
        std::multimap<pizza::Topping, std::string>::iterator toppingsItr = toppings.find(pizza::Topping::NoTopping);
        if (toppingsItr != toppings.end() && toppings.size() == 1)
        {
            toppings.clear();
        }
        toppings.insert({topping, getToppingName(topping)});
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
        cout << "=========Pizza======= " << this << endl;
        cout << "Size: " << getSizeName(size) << endl;
        cout << "Crust: " << getCrustName(crustType) << endl;
        std::multimap<pizza::Topping, std::string>::iterator toppingsItr;
        for (toppingsItr = toppings.begin(); toppingsItr != toppings.end(); ++toppingsItr)
        {
            cout << "Topping: " << getToppingName(toppingsItr->first) << endl;
        }
        cout << "=====================" << endl;
    }

    pizza::Size size;
    pizza::Crust crustType;
    std::multimap<pizza::Topping, std::string> toppings;
};

#endif