#include "CalculusSolver.h"

#include "CalculusSolverDescriptors.h"
#include "Helpers/PyEnums.h"

CalculusSolver::CalculusSolver() : Module("CalculusSolver") 
{
	m_Functions.reserve(EFunction::Count);
	m_Functions.push_back(new FunctionDerivative());
	m_Functions.push_back(new FunctionLimit());
}

EModule CalculusSolver::GetModuleEnum() const { return EModule::CalculusSolver; }