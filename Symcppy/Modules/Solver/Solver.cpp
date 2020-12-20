#include "Solver.h"

#include "SolverDescriptors.h"
#include "Helpers/PyEnums.h"

Solver::Solver() : Module("Solver")
{
	m_Functions.reserve(EFunction::Count);
	m_Functions.push_back(new FunctionZeros(this));
	//m_Functions.push_back(new FunctionValueAt(this)); TEMPORARY
}

EModule Solver::GetModuleEnum() const { return EModule::Solver; }
