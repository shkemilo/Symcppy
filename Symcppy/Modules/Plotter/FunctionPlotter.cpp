#include "FunctionPlotter.h"

#include "FunctionPlotterDescriptors.h"

FunctionPlotter::FunctionPlotter() : Module("Plotter")
{
	m_Functions.reserve(EFunction::Count);
	m_Functions.push_back(new FunctionPlot(this));
}

EModule FunctionPlotter::GetModuleEnum() const 
{
	return EModule::FunctionPlotter;
}