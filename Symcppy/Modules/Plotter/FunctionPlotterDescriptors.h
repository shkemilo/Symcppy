#pragma once
#include "Communication/FunctionDescriptor.h"

class FunctionPlot : public FunctionDescriptor
{
public:
	FunctionPlot(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepeareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

