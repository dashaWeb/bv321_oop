#include <iostream>
using namespace std;


double div(const double& a, const double& b)
{
    const double LIMIT = 1'000'000;
    if (b == 0) {
        throw "Error!!! Division by zero";
    }
    if (b > LIMIT) {
        throw b;
    }
    if (b < -LIMIT) {
        throw (int)b;
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
        catch (const char* ex)
        {
            cout << ex << endl;
        }
        catch (const double& ex)
        {
            cout << "Error. Big number :: " << ex << endl;
        }
        catch (...)
        {
            cout << "Error. small number :: " << endl;
        }
        
    }


}
