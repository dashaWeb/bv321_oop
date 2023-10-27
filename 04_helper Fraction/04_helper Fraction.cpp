#include <iostream>
#include "Fraction.h"
using namespace std;
int main()
{
    Fraction one(15, 45);
    Fraction two(3, 5);

    Fraction res = one + two;
    // 1/2
    cout << one << " + " << two << " = " << res << endl;

    -one;
    cout << one.getFraction() << endl;
    -res;
    cout << res.getFraction() << endl;

    cout << "Enter :: ";
    cin >> one;
    cout << one;

    /*int a = 5, b = 2;
    int c = a + b;*/
}
