#pragma once
#include"Communication/FunctionDescriptor.h"

class Derivate:public FunctionDescriptor
{
public:
	Derivate();
	~Derivate();
protected:
	FunctionResult Execute(ArgCount argCount, va_list& args) const override;
};


class Limit :public FunctionDescriptor
{
public:
	Limit();
	~Limit();
protected:
	FunctionResult Execute(ArgCount argCount, va_list& args) const override;
};
