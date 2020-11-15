#include "SolverDescriptors.h"
#include <iostream>

// Class: FunctionValueAt
FunctionValueAt::FunctionValueAt() : FunctionDescriptor("ValueAt", 2)
{ 
	m_ArgTypes.push_back("string");
	m_ArgTypes.push_back("double");
}

FunctionResult FunctionValueAt::Execute(ArgCount argCount,va_list& args) const
{
	std::cout << "Finding Value of a function at certain point..." << std::endl;
}

// Class: FunctionZeroes
FunctionZeroes::FunctionZeroes() : FunctionDescriptor("Zeroes", 1)
{
	m_ArgTypes.push_back("string");
}

FunctionResult FunctionZeroes::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Finding zeroes in function..." << std::endl;
}

