#pragma once
#include "Communication/FunctionDescriptor.h"

class FunctionZeroes : public FunctionDescriptor
{
public:
	FunctionZeroes(Module* owner);
	
protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepeareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionValueAt : public FunctionDescriptor
{
public:
	FunctionValueAt(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepeareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

