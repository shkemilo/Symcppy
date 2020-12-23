#include <iostream>+
#include "Interface/Function.h"

using namespace std;

int main()
{
	//Function f("(1 + ln(abs(x)))/(x*(1 - ln(abs(x))))");
	//Function f("(x+2)/((ln(x+2))**2)");
	Function f("((x-1)**3)/((x+2)**2)");

	cout << f.GetAnalysis() << endl;
	f.Plot();
	
	cin.get();
	return 0;
}