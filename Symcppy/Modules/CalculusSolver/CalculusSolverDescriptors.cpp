#include "CalculusSolverDescriptors.h"
#include<iostream>

Derivate::Derivate() :FunctionDescriptor("DerivateOfFunction", 1)
{
	this->m_ArgTypes.push_back("string");
}

Derivate::~Derivate()
{

}

FunctionResult Derivate::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Finding derivate of a function..." << std::endl;
}


Limit::Limit() :FunctionDescriptor("LimitAt", 2)
{
	this->m_ArgTypes.push_back("string");
	this->m_ArgTypes.push_back("double");
}


Limit::~Limit()
{

}

FunctionResult Limit::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Finding a limit of a function..." << std::endl;
}