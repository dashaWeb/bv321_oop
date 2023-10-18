#include <iostream>
using namespace std;


class City {
public:
    City():City("No city", "No country",0) // default ctor
    {
        cout << "Default ctor" << endl << endl;
    }
    City(const char* name):City(name,"No country") // parametr 1
    {
        cout << "Params 1 ctor" << endl << endl;

    }
    City(const char* name, const char* country) :City(name,country,0) // parametr 2
    {
        cout << "params 2 ctor" << endl << endl;

    }
    City(const char* name, const char* country, const int& population) // parametr 3
    {

        cout << "params 3 ctor" << endl << endl;
        strCopy(this->city, name);
        strCopy(this->country, country);
        this->population = population;
    }
    ~City() // dtor -> спрацьовує коли видаляємо обєкт
    {
        cout << "Dtor " << this->city << endl;
        if (this->city != nullptr) {
            delete[] this->city;
        }
        if (this->country != nullptr) {
            delete[] this->country;
        }
    }
    inline const char* getCity() const;
    inline const char* getCountry() const;
    inline const int& getPopulation() const; // good style
private:
    char* city = nullptr;
    char* country = nullptr;
    int population;

    void strCopy(char*& dest, const char* source) // dest - куди копіюємо, source - що копіюємо
    {
        /*dest = new char[5000] {'f', 'f'}; // memory leak
        dest = new char[100];*/
        if (dest != nullptr) {
            delete[]dest;
        }
        dest = new char[strlen(source) + 1];
        strcpy_s(dest, strlen(source) + 1, source);
    }
};


int main()
{
    City rivne("Rivne","Ukraine", 243934); // params 3
    cout << "\n\n";
    City lviv("Lviv", "Ukraine"); // params 2
    cout << "\n\n";
    City* kyiv = new City("Kyiv"); // params 1
    cout << "\n\n";
    system("pause");
    delete kyiv;
    kyiv = nullptr;
    City poltava; // default
    cout << "\n\n";

}

inline const char* City::getCity() const
{
    return this->city;
}

inline const char* City::getCountry() const
{
    return this->country;
}

inline const int& City::getPopulation() const
{
    return this->population;
}
