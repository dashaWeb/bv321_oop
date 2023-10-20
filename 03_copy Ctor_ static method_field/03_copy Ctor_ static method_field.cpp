#include <iostream>
#include "Food.h"
using namespace std;

int main()
{

    cout << Food::getCounter() << endl;
    Food milk("Milk", 100, 50);
    Food clone = milk;

    cout << "Origin milk :: ";
    milk.print();
    cout << "Clone milk :: ";
    clone.print();
    cout << "\n++++++++++++++++++++++++++\n\n";
    clone.setName("Bread");
    clone.setKkal(200);
    clone.setWeight(300);
    cout << "Origin milk :: ";
    milk.print();
    cout << "Clone milk :: ";
    clone.print();
    Food banana_clone;
    banana_clone = milk;
    cout << "\n++++++++++++++++++++++++++\n\n";
    cout << "Origin milk :: ";
    milk.print();
    cout << "Clone milk banana :: ";
    banana_clone.print();
    banana_clone.setWeight(2000);
    banana_clone.setName("Banana");
    cout << "Origin milk :: ";
    milk.print();
    cout << "Clone milk banana :: ";
    banana_clone.print();
    cout << Food::getCounter() << endl;

}
