#include <iostream>
#include "Fraction.h"
using namespace std;
int main()
{
    Fraction one(15, 45);
    Fraction two(3, 5);

    Fraction res = one + two;
    cout << one.getFraction() << " + " << two.getFraction() << " = " << res.getFraction() << endl;

    -one;
    cout << one.getFraction() << endl;
    -res;
    cout << res.getFraction() << endl;

    /*int a = 5, b = 2;
    int c = a + b;*/
}
