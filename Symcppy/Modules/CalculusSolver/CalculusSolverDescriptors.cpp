#include "CalculusSolverDescriptors.h"
#include <iostream>
#include<string>

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
	PyObject* str = PyUnicode_AsEncodedString(result, "utf-8", "#");
	const char* function = PyBytes_AS_STRING(str);
	FunctionResult f{ EStatus::Error, nullptr };
	Py_XDECREF(str);
	return FunctionResult{ EStatus::Sucess, (void*)function };
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
	double* value = nullptr;
	value = new double(PyFloat_AsDouble(result));
	if (value == nullptr)
	{
		return FunctionResult{ EStatus::Error, nullptr };
	}
	return FunctionResult{ EStatus::Sucess, value };
}