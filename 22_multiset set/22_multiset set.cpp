#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


template<typename ConTy, typename TE>
void print(const ConTy& cont, const string& prompt = "")
{
    cout << prompt << "\n\t";
    ostream_iterator<TE> oIt(cout, "\t");
    copy(cont.begin(), cont.end(), oIt);
    cout << endl;
}


int main()
{
    /*multiset<int, greater<int>> ml{ 10,45,12,58,4,10,2,4,5,23 };
    print<multiset<int, greater<int>>, int>(ml, "Print multiset");*/

    multiset<int> ml{ 10,45,12,58,4,10,2,4,5,23 };
    print<multiset<int>, int>(ml, "Print multiset");

    ml.insert(50);
    print<multiset<int>, int>(ml, "Print multiset insert");
    ml.erase(45);
    print<multiset<int>, int>(ml, "Print multiset insert");

    for (auto i = ml.begin(); i != ml.end(); i++)
    {
        cout << *i << "\t";
    }cout << endl;

    for (auto i = ml.rbegin(); i != ml.rend(); i++)
    {
        cout << *i << "\t";
    }cout << endl;

    cout << "Min :: " << *ml.begin() << endl;
    cout << "Max :: " << *ml.rbegin() << endl;
    cout << "Count :: " << ml.count(10) << endl;
    int value = 10;
    cout << value << "\t lower_bound \t" << *ml.lower_bound(value) << endl;
    cout << value << "\t upper_bound \t" << *ml.upper_bound(value) << endl;

    print<multiset<int>, int>(ml, "Print multiset insert");
    set<int> st(ml.begin(), ml.end());
    print<set<int>, int>(st, "Print set insert");
    set<int> st2{ 10,4,5,2,8,7,5,4,6,3,2,1 };
    print<set<int>, int>(st2, "Print set insert");

    ostream_iterator<int> itt(cout, "\t");
    cout << "\n\n------------------------- UNION -----------------------------------------" << endl;
    set_union(st.begin(), st.end(), st2.begin(), st2.end(), itt);

    cout << "\n\n------------------------- INTERSECTION -----------------------------------------" << endl;
    set_intersection(st.begin(), st.end(), st2.begin(), st2.end(), itt);


    cout << "\n\n------------------------- DIFFERENCE (st -> st2) -----------------------------------------" << endl;
    set_difference(st.begin(), st.end(), st2.begin(), st2.end(), itt);
    cout << "\n\n------------------------- DIFFERENCE (st2 -> st) -----------------------------------------" << endl;
    set_difference(st2.begin(), st2.end(), st.begin(), st.end(),  itt);

}
