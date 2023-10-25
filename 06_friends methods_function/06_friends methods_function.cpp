#include <iostream>
using namespace std;


class Point {
private:
	int x, y;
	friend void print(const Point& point, string name);
	friend void edit(Point& point);
public:
	Point(const int& x, const int& y) :x{ x }, y{ y } {}
};


void print(const Point& point, string name = "A") 
{
	cout << name << "(" << point.x << "," << point.y << ")" << endl;
}

void edit(Point& point)
{
	cout << "Enter x :: ";
	cin >> point.x;
	cout << "Enter y :: ";
	cin >> point.y;
}

class Pupil;

class Teacher {
public:
	void markMath(Pupil& pupil, int mark);
	void markHistory(Pupil& pupil, int mark);
};

class Pupil {
public:
	Pupil(string name) :name{ name }, math{ 0 }, history{0}
	{

	}
	void print()const {
		cout << "====== " << name << " ======" << endl;
		cout << "Math    :: " << math << endl;
		cout << "History :: " << history << endl;
	}
private:
	int math;
	int history;
	string name;
	friend void Teacher::markMath(Pupil& pupil, int mark);
	friend void Teacher::markHistory(Pupil& pupil, int mark);
};


int main()
{
	/*Point A(5, 2);
	print(A);
	edit(A);
	print(A);*/
	Pupil ivan("Ivan");
	ivan.print();
	Teacher teacher;
	teacher.markMath(ivan, 10);
	ivan.print();
	teacher.markHistory(ivan, 12);
	ivan.print();

}

void Teacher::markMath(Pupil& pupil, int mark)
{
	pupil.math = mark;
}

void Teacher::markHistory(Pupil& pupil, int mark)
{
}
