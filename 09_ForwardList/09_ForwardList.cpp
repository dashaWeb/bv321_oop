#include <iostream>
#include "FList.h"
using namespace std;
int main()
{
    FList<int> list;
    list.addHead(33);
    list.print();
    cout << "Size :: " << list.getSize() << endl;
    list.addHead(45);
    list.print();
    cout << "Size :: " << list.getSize() << endl;
    list.addHead(75);
    list.print();
    cout << "Size :: " << list.getSize() << endl;
    list.addHead(69);
    list.print();
    cout << "Size :: " << list.getSize() << endl;

    cout << "\n\nRemove" << endl;
    list.removeHead();
    list.print();
    cout << "Size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "Size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "Size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "Size :: " << list.getSize() << endl;
    list.removeHead();
    list.print();
    cout << "Size :: " << list.getSize() << endl;

}
