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
	const char* function = new char[256];
	std::string fun;
	Py_ssize_t* size = new Py_ssize_t(256);
	FunctionResult f{ EStatus::Error, nullptr };
	int status = PyObject_AsCharBuffer(result, &function, size);
	if (status == -1) return f;
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