#include <iostream>
#include <forward_list>
#include <list>
#include <algorithm>

using namespace std;



template <typename ContType>
void print(const ContType& cont, const string& prompt = "")
{
	cout << prompt << " :: \n\t";
	for (const auto& el : cont)
	{
		cout << el << "\t";
	}
	cout << endl;
}


int main()
{
	forward_list<int> flist{ 10,15,10,12,10,4,100,14,10,4,10,1 };
	print(flist, "\nPrint forward list");
	flist.push_front(15);
	print(flist, "\nPrint forward list{push_front}");

	int index = 2;
	auto it = flist.begin();
	advance(it, index);

	flist.insert_after(it, 66);
	print(flist, "\nPrint forward list{insert_after}");

	int value = 4;
	it = find(flist.begin(), flist.end(), value);
	while (it != flist.end())
	{
		cout << value << " was found " << distance(flist.begin(), it) << endl;
		auto tmpIt = it;
		++tmpIt;
		if (tmpIt != flist.end()) {
			flist.erase_after(it);
		}
		else {
			cout << "erase after " << value << " is impossible" << endl;
			break;
		}
		++it;
		it = find(it, flist.end(), value);
	}
	print(flist, "\nPrint forward list{erase_after}");

	flist.remove(10);
	print(flist, "\nPrint forward list{remove}");
	int bound = 10;
	//flist.remove_if([bound](const auto& el) {return el > bound; });
	//print(flist, "\nPrint forward list{remove_if}");

	flist.sort();
	print(flist, "\nPrint forward list{sort}");
	flist.sort(greater<int>());
	print(flist, "\nPrint forward list{sort}");

	system("cls");

	list<string> li{ "c++","c#","python","java" };
	print(li, "\nPrint list ");
	li.push_back("assembler");
	li.push_front("js");
	print(li, "\nPrint list ");
	li.sort();
	print(li, "\nPrint list sort");
	li.sort(greater<string>());
	print(li, "\nPrint list sort{desc}");

	char letter = 'c';
	li.remove_if([letter](const auto& el) {return el.find(letter) != string::npos/*-1*/; });
	print(li, "\nPrint list remove if");
}
