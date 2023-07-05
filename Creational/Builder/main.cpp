#include "PepperPassionBuilder.h"
#include <iostream>
using namespace std;

int main()
{
    PepperPassionBuilder builder;

    Pizza *pizza = builder.bakePizza();
    cout << "Working on " << pizza << endl;
    pizza->printPizza();
    delete pizza;
    return 0;
}