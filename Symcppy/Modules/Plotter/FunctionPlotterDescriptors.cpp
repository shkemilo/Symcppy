#include "FunctionPlotterDescriptors.h"
#include <iostream>

// Class: FunctionPlot
FunctionPlot::FunctionPlot(Module* owner) : FunctionDescriptor(owner, "Plot", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionPlot::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionPlot::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionPlot::ConvertResult(PyObject* result) const
{
	return FunctionResult{ EStatus::Sucess, nullptr };
}