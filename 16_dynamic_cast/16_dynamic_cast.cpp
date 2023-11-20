#include <iostream>
#include <vector>
using namespace std;


class Person {
    string name = "None name";

public:
    Person(const string& name)
    {
        setName(name);
    }
    void setName(const string& name) {
        if (!name.empty()) {
            this->name = name;
        }
    }
    virtual void print() const
    {
        cout << "\t " << typeid(*this).name() << endl;
        cout << "\t\t Name :: " << name << endl;
    }
};

class Student : public Person
{
    string specialization = "None Spec";
public:
    Student(const string& name,const string& spec)
        :Person(name)
    {
        setSpec(spec);
    }
    void setSpec(const string& spec) {
        if (!spec.empty()) {
            this->specialization = spec;
        }
    }
    virtual void print() const override
    {
        Person::print();
        cout << "\t " << typeid(*this).name() << endl;
        cout << "\t\t Spec :: " << specialization << endl;
    }
    void learn() const
    {
        cout << "======= Learn =======" << endl;
        cout << "\t\t Spec :: " << specialization << endl;
    }
};

class Aspirant : public Student
{
    string theme = "Important Theme";
public:
    Aspirant(const string& name, const string& spec, const string& theme)
        :Student(name,spec)
    {
        setTheme(theme);
    }
    void setTheme(const string& theme) {
        if (!theme.empty())
        {
            this->theme = theme;
        }
    }
    virtual void print() const override
    {
        Student::print();
        cout << "\t " << typeid(*this).name() << endl;
        cout << "\t\t Theme :: " << theme << endl;
    }
    void write() const
    {
        cout << "======= Write =======" << endl;
        cout << "\t\t Theme :: " << theme << endl;
    }
};

int main()
{
    Person ann("Ann");
    Student ivan("Ivan", "Design");
    Aspirant matviy("Matviy", "CS", "AI");


    ann.print();
    ivan.print();
    matviy.print();

    Student* st = dynamic_cast<Student*>(&ann);
    if (st != nullptr) {
        st->learn();
    }
    else {
        cout << "Error!!! No casting" << endl;
    }

    cout << "\n\n";
    vector<Person*> people{ &ann,&ivan,&matviy };
    for (auto& p : people)
    {
        p->print();

        auto s = dynamic_cast<Student*>(p);
        if (s != nullptr) {
            s->learn();
        }
        auto as = dynamic_cast<Aspirant*>(p);
        if (as != nullptr) {
            as->write();
        }
    }
}

