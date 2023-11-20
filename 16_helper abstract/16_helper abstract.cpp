#include <iostream>
#include <fstream>
#include "Shape.h"
#include <vector>
using namespace std;
int main()
{
    
    //vector<Shape*> shapes{ new Square(5,5),new Rectangle(10,10),new Square(20,20) };


	/*for (auto& i : shapes)
	{
		i->save();
	}*/

	vector<Shape*> result{ new Square, new Rectangle, new Square };
	for (auto& i : result)
	{
		i->load(); 
		i->show();
	}


}
