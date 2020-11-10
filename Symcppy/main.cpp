#include <iostream>

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	cout << "poci" << endl;
	cout << "mista" << endl;
	enum Tip {kajsija=0,breskva};
	Tip t = Tip::breskva;
	int k[2] = {1,12};
	cout << k[static_cast<int>(t)];
	cin.get();
	return 0;
}