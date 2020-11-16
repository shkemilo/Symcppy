#include "FunctionAnalyzer.h"

#include "Communication/PyManager.h"
#include "Helpers/PyEnums.h"
#include "Helpers/Utils.h"
#include "Modules/CalculusSolver/CalculusSolver.h"
#include "Modules/Solver/Solver.h"
#include "Modules/Plotter/FunctionPlotter.h"

FunctionAnalyzer::FunctionAnalyzer(const std::string& function) : m_Function(function)
{

}

FunctionResult FunctionAnalyzer::Plot() const
{
    return PyManager::GetInstance()->CallFunction(EModule::FunctionPlotter, FunctionPlotter::EFunction::Plot, 1, m_Function);
}

FunctionResult FunctionAnalyzer::Derrivative() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Derivative, 1, m_Function);
}

FunctionResult FunctionAnalyzer::Limit(double point) const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Limit, 2, m_Function, point);
}

FunctionResult FunctionAnalyzer::ValueAt(double point) const
{
    return PyManager::GetInstance()->CallFunction(EModule::Solver, Solver::EFunction::ValueAt, 2, m_Function, point);
}

FunctionResult FunctionAnalyzer::GetZeroes() const
{
    return PyManager::GetInstance()->CallFunction(EModule::Solver, Solver::EFunction::Zeroes, 1, m_Function);
}
