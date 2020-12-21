#include <iostream>
#include "Interface/Function.h"

using namespace std;

int main()
{
	std::string functionDescription;
	Function function = Function();
	int operation;
	bool finished = false;
	cout << "Type-in function you want to observe: ";
	std::cin >> functionDescription;
	function.SetFunctionRaw(functionDescription, 'x');
	system("cls");
	while (!finished)
	{
		system("cls");
		cout << "Menu:" << endl << "0. Switch to different function" 
			<< 	endl << "1. Domain" << endl 
			<< "2. Zeros" << endl << "3. Parity"
			<< endl << "4. Periodicity" << endl 
			<< "5. Minimum" << endl << "6. Maximum" 
			<< endl << "7. Monotonicity" << endl 
			<< "8. "<< endl 
			<< "9. Convex-Concave" << endl 
			<< "10. Full function analysis" << endl 
			<< "11. Quit program" << endl;

		cout << "Enter index of preferred operation: ";
		std::cin >> operation;

		while (operation < 0 || operation > 11)
		{
			cout << endl << "Index out of bounds!" << endl;
			cout << "Try again: ";
			std::cin >> operation;
		}

		system("cls");
		switch (operation)
		{
		case(0): cout << "Type-in function you want to observe: ";
			std::cin >> functionDescription;
			function.SetFunctionRaw(functionDescription, 'x'); continue;
		case(1): /* I can't get it how to output domain */ break;
		case(2): /* Out zeros in one line */ break;
		case(3): /* Function parity */ break;
		case(4): /* Function periodicity */ break;
		case(5): /* Function minimum */ break;
		case(6): /* Function maximum */ break;
		case(7): /* Function Monotonicity intervals */ break;
		case(8): /* Function Prevojne tacke eng. */ break;
		case(9): /* Function convex-concave intervals */ break;
		case(10): /* Full function analysis */; break;
		case(11): finished = true;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	return 0;
}