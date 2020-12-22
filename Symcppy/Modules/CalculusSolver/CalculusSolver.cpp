#include "CalculusSolver.h"

#include "CalculusSolverDescriptors.h"
#include "Helpers/PyEnums.h"

CalculusSolver::CalculusSolver() : Module("CalculusSolver") 
{
	m_Functions.reserve(EFunction::Count);
	m_Functions.push_back(new FunctionDerivative(this));
	m_Functions.push_back(new FunctionLimit(this));
	m_Functions.push_back(new FunctionMinimum(this));
	m_Functions.push_back(new FunctionMaximum(this));
	m_Functions.push_back(new FunctionPeriodicity(this));
	m_Functions.push_back(new FunctionDomain(this));
	m_Functions.push_back(new FunctionParity(this));
	m_Functions.push_back(new FunctionMonotonicity(this));
	m_Functions.push_back(new FunctionConvexity(this));
}

EModule CalculusSolver::GetModuleEnum() const 
{ 
	return EModule::CalculusSolver; 
}