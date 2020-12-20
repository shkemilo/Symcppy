#include <iostream>
#include "Interface/Function.h"

using namespace std;

int main()
{
	Function f("x**2 + 10", 'x');
	vector<double> zeros;
	EStatus status = f.GetZeros(zeros);

	for (double zero : zeros)
		cout << zero << " ";
	cout << endl;

	cout << ":)" << endl;
	cin.get();
	return 0;
}