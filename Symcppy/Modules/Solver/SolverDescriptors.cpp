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
	if (result == nullptr)
		return FunctionResult{ EStatus::Error, nullptr };

	double* value = new double(PyFloat_AsDouble(result));
	return FunctionResult{ EStatus::Sucess, value };
}

// Class: FunctionZeros
FunctionZeros::FunctionZeros(Module* owner) : FunctionDescriptor(owner, "Zeros", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionZeros::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return false;
}

PyObject* FunctionZeros::PrepeareArguments(ArgCount argCount, va_list& args) const
{
	return nullptr;
}

FunctionResult FunctionZeros::ConvertResult(PyObject* result) const
{
	return FunctionResult();
}

