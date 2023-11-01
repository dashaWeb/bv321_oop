#include <iostream>
#include "PQueue.h"
using namespace std;
int main()
{
    PQueue<int> queue(5);
    Node<int> node_1(25, 5);
    Node<int> node_2(33, 7);
    Node<int> node_3(45, 6);
    Node<int> node_4(12, 15);
    Node<int> node_5(78, 10);
    Node<int> node_6(63, 3);
    queue.push(node_1);
    queue.print();
    cout << "Size :: " << queue.getSize() << endl;
    queue.push(node_2);
    queue.print();
    cout << "Size :: " << queue.getSize() << endl;
    queue.push(node_3);
    queue.print();
    cout << "Size :: " << queue.getSize() << endl;
    queue.push(node_4);
    queue.print();
    cout << "Size :: " << queue.getSize() << endl;
    queue.push(node_5);
    queue.print();
    cout << "Size :: " << queue.getSize() << endl;
    queue.push(node_6);
    queue.print();
    cout << "Size :: " << queue.getSize() << endl;
}
