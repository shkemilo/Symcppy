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
