#include<iostream>

#include "FunctionPlotterDescriptors.h"

Plot::Plot() :FunctionDescriptor("FunctionPlot", 1)
{
	m_ArgTypes.push_back("string");
}

Plot::~Plot()
{

}

FunctionResult Plot::Execute(ArgCount argCount, va_list& args) const
{
	std::cout << "Plotting a function..." << std::endl;
}