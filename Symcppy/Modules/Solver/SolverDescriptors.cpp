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
	return true;
}

PyObject* FunctionValueAt::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	double point = va_arg(args, double);
	PyObject* pyPoint = PyFloat_FromDouble(point);

	return PyTuple_Pack(2, pyFunction, pyPoint);
}

FunctionResult FunctionValueAt::ConvertResult(PyObject* result) const
{
	double* value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
	EStatus status = value != nullptr ? EStatus::Sucess : EStatus::Error;

	return FunctionResult{ status, value };
}

// Class: FunctionZeros
FunctionZeros::FunctionZeros(Module* owner) : FunctionDescriptor(owner, "GetZeros", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionZeros::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionZeros::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionZeros::ConvertResult(PyObject* result) const
{
	PyObject* pyItem = nullptr;
	std::vector<double>* zeroes = new std::vector<double>();
	FunctionResult functionResult{ EStatus::Error, nullptr };

	int size = PyList_Size(result);
	if (size < 0)
	{
		return functionResult;
	}

	for (int i = 0; i < size; i++)
	{
		pyItem = PyList_GetItem(result, i);
		if (!PyFloat_Check(pyItem))
		{
			return functionResult;
		}

		double element = PyFloat_AsDouble(pyItem);
		if (element == -1.0 && PyErr_Occurred())
		{
			return functionResult;
		}

		zeroes->push_back(element);
	}

	return FunctionResult{EStatus::Sucess, zeroes};
}

