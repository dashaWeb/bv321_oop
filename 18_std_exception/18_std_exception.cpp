#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Cat {
	string name;
	int age;
public:
	Cat(const string& name, const int& age)
	:name(name)
	{
		try
		{
			setAge(age);
		}
		catch (const std::invalid_argument& ex)
		{
			cout << "Type exception :: " << typeid(ex).name() << endl;
			cout << "Error.:: " << ex.what()  << endl;
			this->~Cat();
			throw;
		}
	}
	void setAge(const int& age)
	{
		if (age < 0)
		{
			throw invalid_argument("Age < 0");
		}
		this->age = age;
	}
	~Cat()
	{
		cout << "Dtor " << name << endl;
	}
};

int main()
{
    
	try
	{
		Cat cat("Barsik", -5);
	}
	catch (const std::logic_error& ex)
	{
		cout << "---------------------" << endl;
		cout << "Type exception :: " << typeid(ex).name() << endl;
		cout << "Error.:: " << ex.what() << endl;
	}


    /*string value = "ss1214521";
	try
	{
		int res = stoi(value);
		cout << res << " \t " << res + 1 << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Type exception :: " << typeid(ex).name() << endl;
		cout << "\t" << ex.what()  << endl;
	}

	vector<int> data{ 1,2,3,4 };

	try
	{
		cout << data.at(6) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Type exception :: " << typeid(ex).name() << endl;
		cout << "\t" << ex.what() << endl;
	}*/

	/*size_t size = 2'000'000;
	int* mas;
	int counter = 0;
	try
	{
		while (true)
		{
			mas = new int[size];
			cout << ++counter << endl;
		}
	}
	catch (const std::exception& ex)
	{
		cout << "Type exception :: " << typeid(ex).name() << endl;
		cout << "\t" << ex.what() << endl;
	}*/
    


}
