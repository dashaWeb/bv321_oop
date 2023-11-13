#include <iostream>
using namespace std;

class Person
{
public:
	Person() = default;
	Person(const string& name)
		:name{name} {}
	void think() const {
		cout << name;
		brain.think();
	}
	class Brain
	{
	public:
		Brain() = default;
		void think() const {
			cout << " think" << endl;
		}
	};
private:
	string name;
	Brain brain;
};



int main()
{
	Person ivan("Ivan");
	ivan.think();
}

