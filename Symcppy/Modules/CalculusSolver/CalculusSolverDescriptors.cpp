#include "CalculusSolverDescriptors.h"
#include <iostream>

// Class: FunctionDerivative
FunctionDerivative::FunctionDerivative() : FunctionDescriptor("Derivative", 1)
{
	this->m_ArgTypes.push_back("string");
}

FunctionResult FunctionDerivative::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Finding derivate of a function..." << std::endl;
}

// Class: FunctionLimit
FunctionLimit::FunctionLimit() : FunctionDescriptor("Limit", 2)
{
	this->m_ArgTypes.push_back("string");
	this->m_ArgTypes.push_back("double");
}

FunctionResult FunctionLimit::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Finding a limit of a function..." << std::endl;
}