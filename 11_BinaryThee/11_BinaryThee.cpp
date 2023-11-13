#include <iostream>
#include "Binary.h"
using namespace std;
int main()
{
    Binary<int> tree;
    tree.add(50);
    tree.add(45);
    tree.add(44);
    tree.add(55);
    tree.add(46);
    tree.print();
    tree.deleteData(44);
    tree.deleteData(45);
    tree.deleteData(46);
    tree.deleteData(55);
    tree.deleteData(50);
    tree.print();

}
