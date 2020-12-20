#pragma once
#include "Communication/FunctionDescriptor.h"

class FunctionDerivative : public FunctionDescriptor
{
public:
	FunctionDerivative(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionLimit : public FunctionDescriptor
{
public:
	FunctionLimit(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionMinimum : public FunctionDescriptor
{
public:
	FunctionMinimum(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;
};

class FunctionMaximum : public FunctionDescriptor
{
public:
	FunctionMaximum(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;
};

class FunctionPeriod : public FunctionDescriptor
{
public:
	FunctionPeriod(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;
};