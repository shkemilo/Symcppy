#include "Solver.h"

#include "SolverDescriptors.h"
#include "Helpers/PyEnums.h"

Solver::Solver(const std::string& name) : Module(name)
{
	m_Functions.push_back(new FunctionZeroes());
	m_Functions.push_back(new FunctionValueAt());
}

EModule Solver::GetModuleEnum() const { return EModule::Solver; }
