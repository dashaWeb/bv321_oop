#include <iostream>
#include "Car.h"
using namespace std;

int main()
{
    Engine engine("AB", 400, 2.5, 5, 1);
    engine.print();
    cout << endl;

    Car audi("Audi", engine);
    audi.print();

    Car ford("Ford", { "AA",500,3.0,7,1 });
    ford.print();

    Car bmw("Bmw", "AC", 450, 2.9, 6, 1);
    bmw.print();
}

