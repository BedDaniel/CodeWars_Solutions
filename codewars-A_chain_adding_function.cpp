/*
We want to create a function that will add numbers together when called in succession.
add(1)(2); // == 3

We also want to be able to continue to add numbers to our chain.
add(1)(2)(3); // == 6
add(1)(2)(3)(4); //  == 10
add(1)(2)(3)(4)(5); // == 15
and so on.

A single call should be equal to the number passed in.
add(1); // == 1

We should be able to store the returned values and reuse them.
var addTwo = add(2);
addTwo; // == 2
addTwo + 5; // == 7
addTwo(3); // == 5
addTwo(3)(5); // == 10

We can assume any number being passed in will be valid whole number.
*/
#include <iostream>

class Adder {
public:
    int value;

    Adder(int initialValue) : value(initialValue) {}

    Adder operator()(int x) const {
        return Adder(value + x);
    }

    operator int() const {
        return value;
    }
};

Adder add(int x) {
    return Adder(x);
}



int main(){
    std::cout << add(2) << '\n';
    std::cout << add(1)(2) << '\n';
    std::cout << add(2) << '\n';
    std::cout << add(2) << '\n';

    return 0;
}

/* The most clever solution:

class add
{
public:
    add (int x) : _x( x ) { }
    operator int() { return _x; }
    add operator() (int y) { return add(_x + y); }
    friend bool operator==(const int& a, const add& b) { return a == b._x; }

private:
    int _x;
};

*/