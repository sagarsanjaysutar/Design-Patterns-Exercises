
# Builder Pattern

## _A creational design pattern_

The current design consists of a `iPizzaBuilder` interface which includes common steps to build a pizza. Various types of Pizza can be made by implementing this interface, in this case, we have PepperPassionBuilder.
The unique part of this builder interface is that the client gets to make the pizza step-by-step and in a clean way.

Usage:

1. The client initiates the `Pizza` object via the required `Builder` object.
2. A series of steps (pizza construction) are called using the `Builder`.
3. The `Builder` object returns the fully constructed pizza via `Builder::bakePizza()`.

Note:

1. For the pizza construction, the client does not need to call all the build functions declared in the `Builder` interface.
2. The client can call the build steps in any order.

### Bad Design

A bad alternative to this design would be to have a base `Pizza` class and then have derived classes for each pizza configuration e.g. `BigPizza`, `BigCheesePizza`, `SmallCheesePizza`, etc. In each of these derived classes, we would then have static configurations for toppings, crust, etc. resulting into less flexibility for the client to construct pizza step-by-step.

Another alternative would be to have one giant Pizza constructor which have boolean parameters for configuration like,
`Pizza(bool isSmall, bool hasCheese, bool hasThinCrust,....) resulting into ugly constructor.

## Questions

1. Can the product be modified onces the builder builds it?
   - Product is immutable, once built. [Refer](https://stackoverflow.com/a/1953567)
2. Is it compulsory that all builders share common method construction steps? What if Concrete builder A has more configs than base builder interface?
   - Yes. Concrete A can have more configs, but it needs to implement all base builder's methods. 121 - Dive Into Design Pattern