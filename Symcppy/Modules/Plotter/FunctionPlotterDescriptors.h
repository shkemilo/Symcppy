#pragma once
#include "Communication/FunctionDescriptor.h"

class FunctionPlot : public FunctionDescriptor
{
public:
	FunctionPlot();

protected:
	FunctionResult Execute(ArgCount argCount, va_list& args) const override;

};

