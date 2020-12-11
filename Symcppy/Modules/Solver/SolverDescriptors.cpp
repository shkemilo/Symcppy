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
	double* value =new double(PyFloat_AsDouble(result));
	if (value == nullptr)
	{
		return FunctionResult{ EStatus::Error , nullptr };
	}
	return FunctionResult{EStatus::Sucess,value};
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
	PyObject* item = nullptr;
	std::vector<double>* zeroes = new std::vector<double>();
	FunctionResult f{ EStatus::Error, nullptr };
	int n = PyList_Size(result);
	if (n < 0)
	{
		return f;
	}
	for (int i = 0; i < n; i++)
	{
		item = PyList_GetItem(result, i);
		if (!PyFloat_Check(item))
		{
			return f;
		}
		double element = PyFloat_AsDouble(item);
		if (element == -1.0 && PyErr_Occurred())
		{
			return f;
		}
		zeroes->push_back(element);
	}
	return FunctionResult{EStatus::Sucess, zeroes};
}

