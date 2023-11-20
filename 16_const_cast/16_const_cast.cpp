#include <iostream>
using namespace std;


void func(const int& value)
{
    cout << value << endl;
    //++value;
    ++const_cast<int&>(value);
    cout << value << endl;
    int& ref = const_cast<int&>(value);
    ref = 33;
    cout << value << endl;
}

void funStr(const string& value) {

    /*value[0] = 'Q';*/
    cout << value << endl;
    //++value;
    ++const_cast<string&>(value)[0];
    cout << value << endl;
    string& ref = const_cast<string&>(value);
    ref += "!!!!!!";
    cout << value << endl;
}

int main()
{
    func(2);
    funStr("Hello");
}
