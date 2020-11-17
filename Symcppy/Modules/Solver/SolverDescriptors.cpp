#include "SolverDescriptors.h"
#include <iostream>

// Class: FunctionValueAt
FunctionValueAt::FunctionValueAt(Module* owner) : FunctionDescriptor(owner, "ValueAt", 2)
{ 
	m_ArgTypes.push_back("string");
	m_ArgTypes.push_back("double");
}

bool FunctionValueAt::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return false;
}

PyObject* FunctionValueAt::PrepeareArguments(ArgCount argCount, va_list& args) const
{
	return nullptr;
}

FunctionResult FunctionValueAt::ConvertResult(PyObject* result) const
{
	return FunctionResult();
}

// Class: FunctionZeroes
FunctionZeroes::FunctionZeroes(Module* owner) : FunctionDescriptor(owner, "Zeroes", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionZeroes::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return false;
}

PyObject* FunctionZeroes::PrepeareArguments(ArgCount argCount, va_list& args) const
{
	return nullptr;
}

FunctionResult FunctionZeroes::ConvertResult(PyObject* result) const
{
	return FunctionResult();
}

