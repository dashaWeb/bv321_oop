#include <iostream>
#include "Stack.h"
using namespace std;

template <typename T, typename T2>
struct Node
{
    T first;
    T2 second;
};


int main()
{

    pair<int, double> data(5, 3.6);
    cout << data.first << " " << data.second << endl;
    /*Stack<> stack(5,2);
    stack.print();
    cout << "Top el :: " << stack.top() << endl;

    cout << "===============================\n\n";
    stack.push(2);
    stack.print();
    cout << "Top el :: " << stack.top() << endl;
    system("pause");

    cout << "===============================\n\n";
    stack.push(5);
    stack.print();
    cout << "Size     :: " << stack.size() << endl;
    cout << "Capacity :: " << stack.getCapacity() << endl;
    system("pause");

    cout << "===============================\n\n";
    stack.push(5);
    stack.print();
    cout << "Size     :: " << stack.size() << endl;
    cout << "Capacity :: " << stack.getCapacity() << endl;
    system("pause");

    cout << "===============================\n\n";
    stack.push(5);
    stack.print();
    cout << "Size     :: " << stack.size() << endl;
    cout << "Capacity :: " << stack.getCapacity() << endl;
    system("pause");

    cout << "===============================\n\n";
    stack.pop();
    stack.print();
    cout << "Size     :: " << stack.size() << endl;
    cout << "Capacity :: " << stack.getCapacity() << endl;
    system("pause");*/

    /*while (true)
    {
        cout << "===============================\n\n";
        stack.push(5);
        stack.print();
        cout << "Size     :: " << stack.size() << endl;
        cout << "Capacity :: " << stack.getCapacity() << endl;
        system("pause");
    }
    cout << "===============================\n\n";
    stack.push(5);
    stack.print();
    cout << "Size     :: " << stack.size() << endl;
    cout << "Capacity :: " << stack.getCapacity() << endl;*/
}
