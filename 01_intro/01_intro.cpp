#include <iostream>
#include <string>
using namespace std;


const size_t MIN_POWER = 50;
const size_t MAX_POWER = 1000;

const size_t MAX_SPEED_LOW = 100;
const size_t MAX_SPEED_UP = 350;

const double MIN_VOLUME = 0.7;
const double MAX_VOLUME = 6;

struct Date
{
	size_t day, month, year;
	string getDate() {
		string date = "";
		date += (day < 10 ? "0" + to_string(day) : to_string(day));
		date += ".";
		date += (month < 10 ? "0" + to_string(month) : to_string(month));
		date += ".";
		date += to_string(year);
		return date;
	}
};

class Car {
private:
	string brand = "NoBrand";
	string color = "None";
	size_t power = MIN_POWER;
	size_t max_speed = MAX_SPEED_LOW;
	double volume = MIN_VOLUME;
	Date date{};
public:
	//Car() //  default ctor
	//{
	//    cout << "Default Ctor Test" << endl;
	//    brand = "NoBrand";
	//    color = "None";
	//    power = MIN_POWER;
	//    max_speed = MAX_SPEED_LOW;
	//    volume = MIN_VOLUME;
	//    date.day = 0;
	//    date.month = 0;
	//    date.year = 0;
	//}
	Car(const string& brand, const string& color, Date date) // this = неявний вказівник на обєкт Car
	{
		//this->brand = brand;
		setBrand(brand);
		/*this->color = color;*/
		setColor(color);
		this->date = date;
	}
	void setBrand(const string& brand) { // задача сетера - присвоїти значення для поля 
		/*if (brand.empty() || brand == " ") {
			cout << "Error Value" << endl;
		}
		else {
			this->brand = brand;
		}*/
		/*if (brand.empty() || brand == " ") {
			cout << "Error Value" << endl;
			return;
		}
		this->brand = brand;*/
		if (!brand.empty() && brand != " ") {
			this->brand = brand;
		}
	}
	void setColor(const string& color) {
		if (!color.empty() && color != " ") {
			this->color = color;
		}
	}
	void setPower(const size_t& power) {
		if (power >= MIN_POWER && power <= MAX_POWER) {
			this->power = power;
		}
	}
	void setSpeed(const size_t& speed) {
		if (speed >= MAX_SPEED_LOW && speed <= MAX_SPEED_UP) {
			this->max_speed = speed;
		}
	}
	void setVolume(const double& volume) {
		if (volume >= MIN_VOLUME && volume <= MAX_VOLUME) {
			this->volume = volume;
		}
	}
	string getBrand() {// задача гетера - повертати значення поля 
		return this->brand;
	}
	void print() {
		cout << "\n====================================\n\n";
		cout << "\t\t Brand     :: " << getBrand() << endl;
		cout << "\t\t Color     :: " << this->color << endl;
		cout << "\t\t Power     :: " << this->power << endl;
		cout << "\t\t Max speed :: " << this->max_speed << endl;
		cout << "\t\t Volume    :: " << this->volume << endl;
		cout << "\t\t Date      :: " << this->date.getDate() << endl;
		// 02.02.2020
	}
	void input() {
		string text;
		size_t value;
		double enter;
		cout << "\n====================================\n\n";
		cout << "\t Enter Brand     :: "; getline(cin, text); setBrand(text);
		cout << "\t Enter Color     :: "; getline(cin, text); setColor(text);
		cout << "\t Enter Power     :: "; cin >> value; setPower(value);
		cout << "\t Enter Max speed :: "; cin >> value; setSpeed(value);
		cout << "\t Enter Volume    :: "; cin >> enter; setVolume(enter);
		cout << "\t Enter Date      :: "; cin >> date.day >> date.month >> date.year;
	}
	// public: доступ відкритий, видимі поля та методи за межами класу
	// private: доступ закритий, доступ лише в середині класу до полів та методів
	// protected: захищений, доступ до полів та методів лише в середині класу та у класів наслідників
};


int main()
{
	Car ford("Ford", "White", { 02,05,2012 });
	//ford.brand; --> Error
	cout << "Brand :: " << ford.getBrand() << endl;
	/*ford.setBrand("Mazda");
	cout << "Brand :: " << ford.getBrand() << endl;*/
	Car mazda("Mazda", "Red", { 2,2,2020 });
	cout << "Mazda Brand :: " << mazda.getBrand() << endl;
	ford.print();
	mazda.print();
	cout << "\n\n";
	ford.input();
	ford.print();

}

