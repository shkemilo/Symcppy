#include "CalculusSolverDescriptors.h"
#include <iostream>
#include <string>
#include <stdarg.h>

// Class: FunctionDerivative
FunctionDerivative::FunctionDerivative(Module* owner) : FunctionDescriptor(owner, "Derivative", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionDerivative::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionDerivative::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionDerivative::ConvertResult(PyObject* result) const
{
	const char* function = PyUnicode_AsUTF8(result); // NOTE: It could happen that the pointer data is lost after it loses scope, BE CAREFULL!
	EStatus status = function != nullptr ? EStatus::Sucess : EStatus::Error;

	return FunctionResult{ status, (void*)(function) };
}

// Class: FunctionLimit
FunctionLimit::FunctionLimit(Module* owner) : FunctionDescriptor(owner, "Limit", 2)
{
	m_ArgTypes.push_back("string");
	m_ArgTypes.push_back("double");
}

bool FunctionLimit::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionLimit::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	double point = va_arg(args, double);
	PyObject* pyPoint = PyFloat_FromDouble(point);

	return PyTuple_Pack(2, pyFunction, pyPoint);
}

FunctionResult FunctionLimit::ConvertResult(PyObject* result) const
{
	double* value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
	EStatus status = value != nullptr ? EStatus::Sucess : EStatus::Error;

	return FunctionResult{ status, value };
}


// Class: FunctionMinimum

FunctionMinimum::FunctionMinimum(Module* owner) : FunctionDescriptor(owner, "Minimum", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionMinimum::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionMinimum::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionMinimum::ConvertResult(PyObject* result) const
{
	double* value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
	EStatus status = value != nullptr ? EStatus::Sucess : EStatus::Error;

	return FunctionResult{ status, value };
}

FunctionMaximum::FunctionMaximum(Module* owner) : FunctionDescriptor(owner, "Minimum", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionMaximum::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionMaximum::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionMaximum::ConvertResult(PyObject* result) const
{
	double* value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
	EStatus status = value != nullptr ? EStatus::Sucess : EStatus::Error;

	return FunctionResult{ status, value };
}

FunctionPeriod::FunctionPeriod(Module* owner) : FunctionDescriptor(owner, "Minimum", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionPeriod::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionPeriod::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionPeriod::ConvertResult(PyObject* result) const
{
	double* value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
	EStatus status = value != nullptr ? EStatus::Sucess : EStatus::Error;

	return FunctionResult{ status, value };
}