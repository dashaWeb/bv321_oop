#include <iostream>
#include <vector>
using namespace std;

struct IMove 
{
    virtual void move() const = 0;
    virtual double getSpeed() const = 0;
};
struct IFly :public IMove
{
    virtual void fly() const = 0;
    virtual double getHeight() const = 0;
};
class Bird : public IFly {
    double speed, height;
public:
    Bird(const double& speed, const double& height)
        :speed{speed},height{height}{}
    void fly() const;
    void move() const;
    double getSpeed() const;
    double getHeight() const;
};

class Car :public IMove
{
    string brand;
    double speed;
public:
    Car(const string& brand, const double& speed)
        :brand{brand},speed{speed}{}
    void move() const;
    double getSpeed() const;
};

class Plane :public IFly
{
    string brand;
    double speed, height;
public:
    Plane(const string& brand, const double& speed, const double& height)
        :brand{brand},speed{speed},height{height}{}
    void fly() const;
    void move() const;
    double getSpeed() const;
    double getHeight() const;
};

class Owner
{
    string name;
    IMove* item;
public:
    Owner(const string& name, IMove* item)
        :name{name},item{item}{}

    void print() const
    {
        cout << name << endl;
        item->move();
        cout << "Speed :: " << item->getSpeed() << endl;
        auto s = dynamic_cast<IFly*>(item);
        if (s != nullptr)
        {
            s->fly();
            cout << "Height :: " << s->getHeight() << endl;

        }
    }
};


__interface IShape
{
    double area() const;
};
class Rectangle : public IShape
{
    double width, height;
public:
    Rectangle(const double& width, const double& height)
        :width{width},height{height}
    {}
    double area() const override
    {
        return width * height;
    }
};
class Square : public Rectangle
{
public:
    Square(const double& side)
        :Rectangle(side,side)
    {}
};
class Circle : public IShape
{
    double radius;
public:
    Circle(const double& radius)
        :radius{radius}
    {

    }
    double area() const override {
        return pow(radius, 2) * 3.14;
    }
};
int main()
{

    vector<IShape*> shapes{new Rectangle(4,5),new Square(12),new Circle(15) };
    for (auto& shape : shapes)
    {
        cout << "Res :: " << shape->area() << endl;
    }
    /*Bird bird(50, 100);
    bird.move();
    bird.fly();
    cout << "Speed  :: " << bird.getSpeed() << endl;
    cout << "Height :: " << bird.getHeight() << endl;

    cout << "\n\n";

    Car ford("Ford", 200);
    ford.move();
    cout << "Speed  :: " << ford.getSpeed() << endl;
    cout << "\n\n";

    Plane plane("AK-122",500, 1000);
    plane.move();
    plane.fly();
    cout << "Speed  :: " << plane.getSpeed() << endl;
    cout << "Height :: " << plane.getHeight() << endl;

    cout << "\n\n";*/

    /*IMove* car_ = &ford;
    IFly* pl = &plane;*/

    /*Owner own("Ivan", &plane);
    own.print();*/

   /* vector<Owner> owners{ {"Ivan", & ford}, { "Oleg",&plane }, { "Alex",&bird }};
    for (auto& item : owners)
    {
        item.print();
        cout << "\n-------------------------------\n\n";
    }*/

}

void Bird::move() const
{
    cout << "I Move :: " << typeid(*this).name() << endl;
}

void Bird::fly() const
{
    cout << "I Fly: " << typeid(*this).name() << endl;
}

double Bird::getSpeed() const
{
    return speed;
}

double Bird::getHeight() const
{
    return height;
}

void Car::move() const
{
    cout << brand <<  " Move :: " << typeid(*this).name() << endl;
}

double Car::getSpeed() const
{
    return speed;
}

void Plane::fly() const
{
    cout << brand << " Fly :: " << typeid(*this).name() << endl;
}

void Plane::move() const
{
    cout << brand << " Move :: " << typeid(*this).name() << endl;
}

double Plane::getSpeed() const
{
    return speed;
}

double Plane::getHeight() const
{
    return height;
}
