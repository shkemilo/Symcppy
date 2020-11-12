#include "CalculusSolver.h"
#include "CalculusSolverDescriptors.h"



CalculusSolver::CalculusSolver(const std::string& name) :Module(name) 
{
	m_Functions.push_back(new Derivate());
	m_Functions.push_back(new Limit());
	
}


EModule CalculusSolver::GetModuleEnum() const { return EModule::FunctionModules; }