#include <iostream>
#include <list>
#include <fstream>
using namespace std;



class Book {
	char author[50];
	char title[50];
public:
	Book() = default;
	Book(const char* author, const char* title)
	{
		strcpy_s(this->author, author);
		strcpy_s(this->title, title);
	}
	void print() const
	{
		cout << author << " :: " << title << endl;
	}
};


int main()
{
	/*list<Book> lib{ {"Tony Gaddis","C++ for beginning"},{"Stiven Prata","Moder in C++"} };

	ofstream outFile("db.dat", ios_base::binary);
	Book tmp;
	for (auto i = lib.begin(); i != lib.end(); i++)
	{
		tmp = *i;
		outFile.write((char*)&tmp,sizeof(Book));
	}
	outFile.close();*/

	list<Book> res;

	ifstream inFile("db.dat", ios_base::binary);

	Book ress;
	try
	{
		while (inFile.read((char*)&ress, sizeof(Book)))
		{
			res.push_back(ress);
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	
	inFile.close();

	for (auto& i : res)
	{
		i.print();
	}

}
