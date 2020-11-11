
#include "Solver.h"
#include"SolverDescriptors.h"
Solver::Solver(const std::string& name):Module(name)
{
	this->m_Functions.push_back(new FunctionZeroes());
	this->m_Functions.push_back(new FunctionValueAt());
}
/*
EStatus Solver::GetZeroes(std::vector<double>& zeroes)
{
	//this->CallFunction(0,1,)
}

EStatus Solver::GetValueAt(const std::string& function, const double& point, double& valueAt)
{
	//this->CallFunction(1,2,)
}
*/