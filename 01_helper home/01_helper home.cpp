#include <iostream>
#include <string>
using namespace std;


class Fraction {
private:
    int num;
    int denum;
public:
    Fraction(const int& num, const int& denum)
    {
        this->num = num;
        this->denum = denum;
    }
    string toString() {
        return to_string(this->num) + "/" + to_string(this->denum);
    }
    Fraction sum(const Fraction& other) {
        // 1/2 + 3/5 --> denum (2 * 5 --> 10); num(1 * 5 + 3 * 2 --> 11) --> 11/10
        /*int denum = this->denum * other.denum;
        int num = this->num * other.denum + other.num * this->denum;*/
        Fraction res(this->num * other.denum + other.num * this->denum, this->denum *other.denum);
        return res;
    }
};

int main()
{
    Fraction one(1, 2);
    Fraction two(3, 5);
    Fraction res = one.sum(two);
    cout << "Sum :: " << one.toString() << " + " << two.toString() << " = " << res.toString() << endl;
}
