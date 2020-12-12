#include "FunctionPlotterDescriptors.h"
#include <iostream>

// Class: FunctionPlot
FunctionPlot::FunctionPlot(Module* owner) : FunctionDescriptor(owner, "Plot", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionPlot::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return false;
}

PyObject* FunctionPlot::PrepeareArguments(ArgCount argCount, va_list& args) const
{
	return nullptr;
}

FunctionResult FunctionPlot::ConvertResult(PyObject* result) const
{
	return FunctionResult{ EStatus::Sucess, nullptr };
}