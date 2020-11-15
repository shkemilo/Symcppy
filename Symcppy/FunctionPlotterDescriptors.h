#pragma once
#include "Communication/FunctionDescriptor.h"

class Plot : public FunctionDescriptor
{
public:
	Plot();
	~Plot();

protected:
	FunctionResult Execute(ArgCount argCount, va_list& args) const override;

};

