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
    return PyManager::GetInstance()->CallFunction(EModule::FunctionPlotter, FunctionPlotter::EFunction::Plot, 1, m_Function.c_str());
}

FunctionResult FunctionAnalyzer::Derrivative() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Derivative, 1, m_Function.c_str());
}

FunctionResult FunctionAnalyzer::Limit(double point, ELimitFrom from) const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Limit, 3, m_Function.c_str(), point, from);
}

FunctionResult FunctionAnalyzer::ValueAt(double point) const
{
    return PyManager::GetInstance()->CallFunction(EModule::Solver, Solver::EFunction::ValueAt, 2, m_Function.c_str(), point);
}

FunctionResult FunctionAnalyzer::GetZeros() const
{
    return PyManager::GetInstance()->CallFunction(EModule::Solver, Solver::EFunction::Zeros, 1, m_Function.c_str());
}

FunctionResult FunctionAnalyzer::GetDomain() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Domain, 1, m_Function.c_str());
}

FunctionResult FunctionAnalyzer::GetPeriodicity() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Periodicity, 1, m_Function.c_str());
}

FunctionResult FunctionAnalyzer::GetParity() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Parity, 1, m_Function.c_str());
}

FunctionResult FunctionAnalyzer::GetMin() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Minimum, 1, m_Function.c_str());
}

FunctionResult FunctionAnalyzer::GetMax() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Maximum, 1, m_Function.c_str());;
}

FunctionResult FunctionAnalyzer::GetMonotonicity() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Monotonicity, 1, m_Function.c_str());;
}

FunctionResult FunctionAnalyzer::GetConvexity() const
{
    return PyManager::GetInstance()->CallFunction(EModule::CalculusSolver, CalculusSolver::EFunction::Convexity, 1, m_Function.c_str());;
}
