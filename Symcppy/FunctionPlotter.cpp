
#include "FunctionPlotter.h"
#include"FunctionPlotterDescriptors.h"

FunctionPlotter::FunctionPlotter(const std::string& name) :Module(name)
{
	m_Functions.push_back(new Plot());
}