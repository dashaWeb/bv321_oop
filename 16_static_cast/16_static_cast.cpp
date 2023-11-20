#include <iostream>
using namespace std;

enum Colors
{
	RED, GREEN, BLUE
};

class Point {
public:
	int x = 0, y = 0;
	virtual void print() const
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};
class Point3D : public Point
{
public:
	int z = 0;
	void print() const override
	{
		cout << "(" << x << "," << y << "," << z << ")" << endl;
	}
};
int main()
{
	//int R1 = 2, R2 = 4, R3 = 8;
	//double R0 = 1.0 / R1 + 1.0 / R2 + 1.0 / R3;
	//R0 = 1 / R0;
	//cout << "Result :: " << R0 << endl; // Error


	//int a = 128; // 4 bytes
	//char s = a; // 1 bytes
	//cout << (int)s << endl;
	//// 0 1 2 3 4 5 6 7 8 ..... 255
	cout << static_cast<int>(Colors::RED) << endl; // явне перетворення типів
	cout << static_cast<char>(122) << endl; // явне перетворення типів
	int col = 3;
	Colors PINK = static_cast<Colors>(3);

	Point point;
	point.x = 1;
	point.y = 2;
	cout << "Point 2D :: ";
	point.print();

	Point3D point3d;
	point3d.x = 5;
	point3d.y = 6;
	point3d.z = 7;
	cout << "Point 3D :: ";
	point3d.print();

	Point res = point3d;
	cout << "Point 3D -> 2D :: ";
	res.print();
	cout << typeid(res).name() << endl;
	Point3D res_ = static_cast<Point3D&>(res);
	cout << "Point 2D -> 3D :: ";
	res_.print();
	cout << typeid(res_).name() << endl;

	if (typeid(res).name() == typeid(res_).name()) {
		cout << "\n\n Result casting :: " << endl;
		Point3D res_ = static_cast<Point3D&>(res);
		cout << "Point 2D -> 3D :: ";
		res_.print();
	}
}
