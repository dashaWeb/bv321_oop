#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const size_t SIZE = 20;
class Train
{
	size_t number;
	char destination[SIZE];
	char from[SIZE];
public:
	Train() = default;
	Train(const size_t& number, const char* from, const char* dest)
		:number(number)
	{
		strcpy_s(this->from, from);
		strcpy_s(this->destination, dest);
	}
	void print() const
	{
		cout << "\t Number of Train :: " << number << endl;
		cout << "\t Place from      :: " << from << endl;
		cout << "\t Destination     :: " << destination << endl;
	}
};


int main()
{
	fstream file("trains.dat", ios_base::out | ios_base::in | ios_base::binary);

	Train train(145, "Rivne", "Lviv");
	file.write((char*)&train, sizeof(Train));


	Train arrTrains[2]{
		{548,"Kyiv","Kharkiv"},
		{487,"Lviv","Odesa"}
	};

	file.write(reinterpret_cast<char*>(arrTrains), sizeof(arrTrains));

	
	vector<Train> vecTrains{
		{785,"Poltava","Rivne"},
		{879, "Rivne","Paris"}
	};
	file.write(reinterpret_cast<char*>(vecTrains.data()), vecTrains.size() * sizeof(Train));

	// read

	cout << "File Cursor :: " << file.tellg() << endl;
	file.seekg(0);
	cout << "File Cursor :: " << file.tellg() << endl;

	cout << "\n\n";

	Train res;
	while (file.read(reinterpret_cast<char*>(&res), sizeof(Train)))
	{
		cout << "\n---------------------\n";
		res.print();
	}
	
	cout << "File Cursor :: " << file.tellg() << endl;
	file.clear();
	file.seekg(0);
	cout << "File Cursor :: " << file.tellg() << endl;

	vector<Train> results;
	while (file.read(reinterpret_cast<char*>(&res), sizeof(Train)))
	{
		results.push_back(res);
	}

	cout << "----- Print vector trains -------\n";
	for (auto& el : results)
	{
		el.print(); 
		cout << endl;
	}


	cout << "File Cursor :: " << file.tellg() << endl;
	file.clear();
	file.seekg(0);
	cout << "File Cursor :: " << file.tellg() << endl;

	cout << "end file :: " << endl;
	file.seekg(0, ios::end);
	cout << "File Cursor :: " << file.tellg() << endl;
	int count = file.tellg() / sizeof(Train);
	cout << "Number of Trains :: " << count << endl;
	file.seekg(0);
	cout << "File Cursor :: " << file.tellg() << endl;

	results.clear();
	results.resize(count);
	file.read(reinterpret_cast<char*>(results.data()), sizeof(Train) * count);
	cout << "----- Print vector trains -------\n";
	for (auto& el : results)
	{
		el.print();
		cout << endl;
	}

	int index = 2;
	file.seekg(sizeof(Train) * index);
	cout << "\n\nFile Cursor :: " << file.tellg() << endl;
	Train new_tr(999, "Rivne", "Lviv");
	file.read((char*)&new_tr, sizeof(Train));
	new_tr.print();
	// fstream --> read, write; Mode --> in, out, app, binary (|)
	// ofstream --> write
	// ifstream --> read
	 /*int number = 1245856;
	 ofstream file("number.txt");
	 file << number;
	 file.close();*/

	//int number = 1245856;
	//ofstream file("number_bi.txt",ios_base::binary);
	//file.write((char*)&number, sizeof(int));
	////file << number;
	//file.close();

	 /*int res;
	 ifstream file("number_bi.txt");
	 file.read((char*)&res, sizeof(int));
	 file.close();
	 cout << "Result :: " << res << endl;*/


	 //string text = "lorem ipsum";
	 //char text[50] = "lorem ipsum";
	 /*char text = 's';
	 ofstream file("text.txt");
	 file << text;
	 file.close();*/

	//ifstream file("text.txt");
	//char s;
	/*while (file >> s)
	{
		cout << s;
	}*/
	/*while (file.get(s))
	{
		cout << s;
	}*/
	/*char s[100];
	while (file.getline(s,100))
	{
		cout << s << endl;
	}*/
	/*char s[100];
	while (file >> s)
	{
		cout << s << endl;
	}*/

	/*string s;
	while (getline(file,s))
	{
		cout << s << endl;
	}*/
}
