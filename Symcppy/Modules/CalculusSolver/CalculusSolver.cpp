#include "CalculusSolver.h"

#include "CalculusSolverDescriptors.h"
#include "Helpers/PyEnums.h"

CalculusSolver::CalculusSolver(const std::string& name) :Module(name) 
{
	m_Functions.push_back(new FunctionDerivative());
	m_Functions.push_back(new FunctionLimit());
}

EModule CalculusSolver::GetModuleEnum() const { return EModule::CalculusSolver; }