#include "PepperPassionBuilder.h"
#include "products/namespace.h"
#include <iostream>
using namespace std;

int main()
{
    // Configuring the product
    PepperPassionBuilder builder;
    builder.setSize(pizza::Size::Classic);
    builder.addTopping(pizza::Topping::Olives);
    builder.addTopping(pizza::Topping::Cheese);

    // Building the product
    Pizza *pizza = builder.bakePizza();
    pizza->printPizza();
    delete pizza;
    return 0;
}