#include <iostream>
#include "MyExceptionStd.h"
using namespace std;


double div(const double& a, const double& b)
{
    const double LIMIT = 1'000'000;
    if (b == 0) {
        throw DivisionByZeroException("Error!! Division by zero");
    }
    if (b > LIMIT) {
        throw TooBigValuExceprion("Too big value");
    }
    if (b < -LIMIT) {
        throw TooSmallValuExceprion("Too small value");
    }
    return a / b;
}

void my_terminate()
{
    cout << "Call my terminate" << endl;
    exit(EXIT_SUCCESS);
}
int main()
{

    set_terminate(my_terminate);
    double a, b, result;
    while (cin >> a >> b)
    {
        try
        {
            result = div(a, b);
            cout << a << " / " << b << " = " << result << endl;
        }
        catch (DivisionByZeroException ex)
        {
            cout << "Type exception :: " << typeid(ex).name() << endl;
            cout << "Error. Big number :: " << ex.what() << endl;
        }
        catch (TooBigValuExceprion ex)
        {
            cout << "Type exception :: " << typeid(ex).name() << endl;
            cout << "Error. Big number :: " << ex.what() << "\t bad value :: " << ex.getValue() << endl;
        }
        catch (underflow_error ex)
        {
            cout << "Type exception :: " << typeid(ex).name() << endl;
            cout << "Error. Big number :: " << ex.what() << "\t bad value :: " << static_cast<TooSmallValuExceprion*>(&ex)->getValue() << endl;
        }
    }


}
