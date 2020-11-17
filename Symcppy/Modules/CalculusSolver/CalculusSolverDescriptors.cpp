#include "CalculusSolverDescriptors.h"
#include <iostream>

// Class: FunctionDerivative
FunctionDerivative::FunctionDerivative(Module* owner) : FunctionDescriptor(owner, "Derivative", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionDerivative::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return false;
}

PyObject* FunctionDerivative::PrepeareArguments(ArgCount argCount, va_list& args) const
{
	return nullptr;
}

FunctionResult FunctionDerivative::ConvertResult(PyObject* result) const
{
	return FunctionResult();
}

// Class: FunctionLimit
FunctionLimit::FunctionLimit(Module* owner) : FunctionDescriptor(owner, "Limit", 2)
{
	m_ArgTypes.push_back("string");
	m_ArgTypes.push_back("double");
}

bool FunctionLimit::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return false;
}

PyObject* FunctionLimit::PrepeareArguments(ArgCount argCount, va_list& args) const
{
	return nullptr;
}

FunctionResult FunctionLimit::ConvertResult(PyObject* result) const
{
	return FunctionResult();
}