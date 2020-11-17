#include "FunctionPlotterDescriptors.h"
#include <iostream>

// Class: FunctionPlot
FunctionPlot::FunctionPlot() : FunctionDescriptor("Plot", 1)
{
	m_ArgTypes.push_back("string");
}

FunctionResult FunctionPlot::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Plotting a function..." << std::endl;
}