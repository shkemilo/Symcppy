#pragma once
#include"Communication/FunctionDescriptor.h"

class FunctionZeroes:public FunctionDescriptor
{
public:
	FunctionZeroes();
	~FunctionZeroes();
protected:
 	FunctionResult Execute(ArgCount argCount,va_list& args) const override;
};


class FunctionValueAt :public FunctionDescriptor
{
public:
	FunctionValueAt();
	~FunctionValueAt();
protected:
	FunctionResult Execute(ArgCount, va_list&) const override;
};

