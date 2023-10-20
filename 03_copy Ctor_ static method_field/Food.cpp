#include "Food.h"

void Food::print() const
{
	cout << "\n============ "<<this->id<<" ==============\n";
	cout << "\t Name   :: " << getName() << endl;
	cout << "\t KKal   :: " << getKkal() << endl;
	cout << "\t Weight :: " << getWeight() << endl;
}

void Food::strCopy(char*& dest, const char* source)
{
	//memry leak
	if (dest != nullptr) {
		delete[] dest;
	}
	dest = new char[strlen(source)+1];
	strcpy_s(dest, strlen(source) + 1, source);
}

size_t Food::counter = 0;