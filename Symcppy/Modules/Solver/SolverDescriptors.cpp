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
	FunctionResult functionResult;
	if (PyFloat_Check(result))
	{
		functionResult.value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
		functionResult.result = EStatus::Sucess;
	}
	else if (PyUnicode_Check(result))
	{
		const char* message = PyUnicode_AsUTF8(result);
		if (message == K_POSITIVE_INF)
		{
			functionResult.result = EStatus::MathInf;
			functionResult.value = new double(K_POSITIVE_INF_VALUE);
		}
		else if (message == K_NEGATIVE_INF)
		{
			functionResult.result = EStatus::MathInf;
			functionResult.value = new double(K_NEGATIVE_INF_VALUE);
		}
		else
		{
			functionResult.result = EStatus::MathUndefined;
		}
	}

	return functionResult;
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

