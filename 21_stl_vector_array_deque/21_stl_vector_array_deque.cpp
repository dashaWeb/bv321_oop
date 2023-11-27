#include <iostream>
#include <array>
#include <vector>
#include <deque>

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

bool div_3(int a)
{
	return a % 5 == 0;
}

int inc(int a)
{
	return a + 2;
}
int main()
{
	const size_t SIZE = 5;
	array<int, SIZE> arr{ 4,-5,33,48,15 };
	cout << "Print container array [index] :: \n\t";
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	cout << "Print container array [iterator] :: \n\t";
	for (array<int, SIZE>::const_iterator it = arr.cbegin(); it != arr.cend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;

	cout << "Print container array [reverse_iterator] :: \n\t";
	for (auto it = arr.crbegin(); it != arr.crend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
	print(arr, "Print array");

	try
	{
		arr.at(5) = 777;

	}
	catch (const std::exception& ex)
	{
		cout << "Bad index :: " << ex.what() << endl;
	}


	vector<int> v(arr.rbegin(), arr.rend());
	print(v, "Print vector [copy array]");
	v.push_back(777);
	print(v, "Print vector [push_back]");
	v.insert(v.begin() + v.size() / 2, 333);
	print(v, "Print vector [insert]");
	/*cout << "Size     :: " << v.size() << endl;
	cout << "Capacity :: " << v.capacity() << endl;

	v.clear();

	cout << "\n\nSize     :: " << v.size() << endl;
	cout << "Capacity :: " << v.capacity() << endl;*/
	/*v.pop_back();
	print(v, "Print vector [pop_back]");
	v.erase(v.begin() + v.size() / 2, v.end());
	print(v, "Print vector [erase]");*/

	deque<int> d(v.begin(), v.begin() + v.size() / 2);
	print(d, "Print deque");
	d.push_front(777);
	d.push_back(777);
	d.insert(d.begin() + 2, 777);
	print(d, "Print deque [push_front]");

	auto it = find(d.begin(), d.end(), 777);
	while (it != d.end())
	{
		cout << "Value :: " << *it << "\t Index :: " << it - d.begin() << endl;
		it = find(it + 1, d.end(), 777);
	}
	cout << "Count 777 :: " << count(d.begin(), d.end(), 777) << endl;
	it = min_element(d.begin(), d.end());
	cout << "Min:: " << *it << endl;
	it = max_element(d.begin(), d.end());
	cout << "Max:: " << *it << endl;
	sort(d.begin(), d.end());
	print(d, "Print deque [sort ABC]");
	sort(d.rbegin(), d.rend());
	print(d, "Print deque [sort DEST]");

	it = find_if(d.begin(), d.end(), div_3);
	cout << "Value :: " << *it << "\t Index :: " << it - d.begin() << endl;
	transform(d.begin(), d.end(), d.begin(), inc);
	print(d, "Print deque [sort DEST]");

	//double test = 22;

	//auto fun = [test](int a, int b, int c) ->double {
	//	//test = 111;
	//	double sum = (double)a + b + c + test;
	//	return sum;
	//};
	//cout << fun(1, 2, 3) << "\t " << test << endl;

	transform(d.begin(), d.end(), d.begin(), [](int a) {return a / 2; });
	print(d, "Print deque [sort DEST]");

	it = find_if(d.begin(), d.end(), [](int a) {return a % 2 > 0 && a < 100; });
	while (it != d.end())
	{
		cout << "Value :: " << *it << "\t Index :: " << it - d.begin() << endl; 
		it = find_if(it+1, d.end(), [](int a) {return a  > 0 && a < 100; });
	}
}
