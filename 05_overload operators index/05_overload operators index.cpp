#include <iostream>
#include "MyArray.h"
using namespace std;


int main()
{
    MyArray arr(10);
    arr.print();
    cout << arr[0] << endl;
    arr[0] = 13;
    arr.print();
    for (size_t i = 0; i < 10; i++)
    {
        arr[i] = rand() % 20;
    }
    arr.print();

    MyArray res = arr(2, 7);
    res.print();
    arr.print();
    int a = 66;
    cout << "Test operator << \n";
    cout << res << endl;
    cout << "Test operator << \n";
    cout << arr << endl;
    cout << "Test operator >> \n";
    cin >> res;
    cout << res;
}
