#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


using id = int;
using name = string;

using author = string;
using title = string;

template <typename T>
void print(const T& map, const string& prompt)
{
	cout << prompt << "::\n";
	for (auto& el : map)
	{
		cout << "\t Id :: " << el.first << "\t Name :: " << el.second << endl;
	}
}

int main()
{

	map<id, name> people
	{
		pair<id,name>{555,"Anna"},
		make_pair(777,"Denis"),
		{333,"Oleg"}
	};

	print(people, "Print example map :: ");
	people.insert({ 666,"Max" });
	print(people, "Print example map :: ");

	people[333] = "Olena";
	people[444] = "Maria";
	//cout << "Test get key :: " << people[333] << endl;
	try
	{
		cout << "Test get key :: " << people.at(1000) << endl;

	}
	catch (const std::exception& ex)
	{
		cout << "Error message :: " << ex.what() << endl;
	}

	print(people, "Print example map :: ");

	cout << "\n\nTest print iterator :: \n";
	for (auto i = people.begin(); i != people.end(); i++)
	{
		cout << "\t Id :: " << i->first << "\t Name :: " << i->second << endl;
	}
	cout << "\n\nTest print reverse iterator :: \n";
	for (auto i = people.rbegin(); i != people.rend(); i++)
	{
		cout << "\t Id :: " << i->first << "\t Name :: " << i->second << endl;
	}


	cout << "\n\nTest find key :: \n";
	id key = 333;
	auto it = people.find(key);
	if (it != people.end()) {
		cout << "\t Id :: " << it->first << "\t Name :: " << it->second << endl;
		people.erase(key);
	}
	else {
		cout << "Key not found" << endl;
	}

	print(people, "Print example map :: ");
	cout << "\n\nTest find Denis :: \n";
	it = find_if(people.begin(), people.end(), [](auto el) {return el.second == "Denis"; });
	if (it != people.end()) {
		cout << "\t Id :: " << it->first << "\t Name :: " << it->second << endl;
		people.erase(it);
	}
	else {
		cout << "Denis not found" << endl;
	}

	print(people, "Print example map :: ");

	cout << "\n\nTest find lower_bound :: \n";
	it = people.lower_bound(555);
	cout << "\t Id :: " << it->first << "\t Name :: " << it->second << endl;
	cout << "\n\nTest find upper_bound :: \n";
	it = people.upper_bound(555);
	cout << "\t Id :: " << it->first << "\t Name :: " << it->second << endl;

	system("pause");
	system("cls");

	multimap<author, title> library
	{
		{"Tony Gaddis","C++ for beginning"},
		{"Tony Gaddis","Python for beginning"},
		{"Stiven Prata","Modern C++"},
		{"Tony Gaddis","Java for beginning"},
		{"Stiven Prata","Modern C"}
	};
	print(library, "Print multimap :: ");
	auto itt = find_if(library.begin(), library.end(), [](auto el) {return el.second == "Python for beginning"; });
	//library.erase("Tony Gaddis");
	//advance(itt, 2);
	library.erase(itt);
	print(library, "\n\nPrint multimap :: ");

	auto res = library.equal_range("Tony Gaddis");
	cout << "\n\nTest find equal_range :: \n";
	for (auto i = res.first; i != res.second; i++)
	{
		cout << "\t Id :: " << i->first << "\t Name :: " << i->second << endl;
	}

}
