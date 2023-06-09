#ifndef PIZZA_H
#define PIZZA_H

#include "namespace.h"
#include <vector>
#include <iostream>
using namespace std;

class Pizza
{
private:
    Pizza()
    {
        cout << "Pizza::Pizza()" << endl;
    }
    ~Pizza()
    {
        cout << "Pizza::~Pizza()" << endl;
    }

public:
    pizza::Size size;
    pizza::Crust crustType;
    vector<pizza::Topping> toppings;
};

#endif