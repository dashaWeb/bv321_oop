#include <iostream>
#include "Animal.h"
#include "Walf.h"
#include "Lion.h"
using namespace std;
int main()
{
    /*Animal animal("None", 5);
    animal.print();*/
    
    Walf walf("Walf", 3, 20);
    walf.print();

    Dog dog("Dog",4, 15);
    dog.print();

    Lion lion("Lion", 5, 12);
    lion.print();

    cout << "\n\n Print ZOO :: \n";
    Animal** zoo = new Animal * [4] {&walf, & dog, & lion, new Walf("Walf2", 3, 20)};
    for (size_t i = 0; i < 4; i++)
    {
        zoo[i]->print();
        zoo[i]->move();
        zoo[i]->eat();
    }

}
