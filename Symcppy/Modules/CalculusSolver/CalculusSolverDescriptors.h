#pragma once
#include "Communication/FunctionDescriptor.h"

class FunctionDerivative : public FunctionDescriptor
{
public:
	FunctionDerivative();

protected:
	FunctionResult Execute(ArgCount argCount, va_list& args) const override;

};

class FunctionLimit : public FunctionDescriptor
{
public:
	FunctionLimit();

protected:
	FunctionResult Execute(ArgCount argCount, va_list& args) const override;

};
