#ifndef NAMESPACE_H
#define NAMESPACE_H
namespace pizza
{
    enum Size
    {
        Small = 0,
        Classic = 1,
        Large = 2
    };

    enum Crust
    {
        Traditional = 0,
        Stuffed = 1,
        DeepPan = 2,
        Thin = 3
    };

    enum Topping
    {
        NoTopping = 0,
        Cheese = 1,
        Olives = 2,
        Mushrooms = 3
    };
}

#endif