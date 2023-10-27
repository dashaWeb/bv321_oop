#include <iostream>
#include "Matrix.h"
using namespace std;

//template<typename T>
//T sum(T a, T b) {
//    return a + b;
//}

//int sum(int a, int b) {
//    return a + b;
//}
//
//double sum(double a, double b) {
//    return a + b;
//}
int main()
{
    Matrix<> mas(5);
    cout << "Test array int :: \n";
    cout << mas;
    Matrix<double, 10, 5> mas_d(2.25);
    cout << "Test array double :: \n";
    cout << mas_d;

    Matrix<> res = mas + 10;
    cout << "Test array sum :: \n";
    cout << res;

    cout << res(0, 0) << endl;
    res(0, 0) = 33;
    cout << res<< endl;

}
