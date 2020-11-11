#include "SolverDescriptors.h"
#include <iostream>

FunctionValueAt::FunctionValueAt() :FunctionDescriptor("FunctionValueAt", 2) 
{ 
	m_ArgTypes.push_back("string");
	m_ArgTypes.push_back("double");
}


FunctionResult FunctionValueAt::Execute(ArgCount argCount,va_list& args) const
{
	std::cout << "Finding Value of a function at certain point..." << std::endl;
}

FunctionValueAt::~FunctionValueAt()
{

}

FunctionZeroes::FunctionZeroes() :FunctionDescriptor("FunctionZeroes", 1)
{
	m_ArgTypes.push_back("string");
}

FunctionZeroes::~FunctionZeroes()
{

}


FunctionResult FunctionZeroes::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Finding zeroes in function..." << std::endl;
}

