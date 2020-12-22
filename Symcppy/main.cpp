#include <iostream>
#include "Interface/Function.h"

using namespace std;

int main()
{
	Function f("x**3");

	cout << f.GetAnalysis(false) << endl;
	
	cin.get();
	return 0;
}