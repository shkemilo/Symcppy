#include <iostream>

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	cout << "poci" << endl;
	cout << "mista" << endl;

	int a = 0;
	double b = 2;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cin.get();
	return 0;
}