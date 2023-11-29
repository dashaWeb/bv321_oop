#include <iostream>
#include <vector>

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
	vector<int> v{ 12,10,15 };
	print(v);

	auto it = v.begin();
	// 12,10,15

	print(v);
	int size = v.size();

	for (int i = 0; i < size*2; i+=2)
	{
		it = v.begin();
		v.insert(it + i + 1, v[i]);
	}
	print(v);
}
