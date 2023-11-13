#include <iostream>
#include "DList.h"
using namespace std;


int main()
{
    DList<int> list;
    list.addHead(12);
    cout << "Print :: ";
    list.print();
    list.addHead(22);
    cout << "Print :: ";
    list.print();
    list.addHead(33);
    cout << "Print :: ";
    list.print();
    list.addTail(10);
    cout << "Print :: ";
    list.print();
    list.addTail(20);
    cout << "Print :: ";
    list.print();
    list.addTail(30);
    cout << "Print :: ";
    list.print();
    list.removeData(12);
    cout << "Print :: ";
    list.print();

    DList<int> clone;
    clone = list;
    cout << "Print Original :: ";
    list.print();
    cout << "Print Clone    :: ";
    clone.print();
    clone.removeHead();
    cout << "Print Original :: ";
    list.print();
    cout << "Print Clone    :: ";
    clone.print();
    DList<int>* res;
    res = clone + list;
    cout << "Print Result   :: ";
    res->print();
   /* clone.clear();
    cout << "Print Clone    :: ";
    clone.print();*/
    //list.printR();
    //cout << "\n\n";
    //list.printR();
    /*list.removeHead();
    cout << "Print :: ";
    list.print();
    list.removeHead();
    cout << "Print :: ";
    list.print();
    list.removeHead();
    cout << "Print :: ";
    list.print();
    list.removeHead();
    cout << "Print :: ";
    list.print();
    list.removeHead();
    cout << "Print :: ";
    list.print();
    list.removeHead();
    cout << "Print :: ";
    list.print();
    list.removeHead();
    cout << "Print :: ";
    list.print();*/

}
