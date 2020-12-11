#include "AnalysisDescription.h"

#include "Function.h"

AnalysisDescription::AnalysisDescription(const Function& owner, const Function& derrivative, const std::vector<double>& zeros) : m_Owner(owner), m_Derrivative(derrivative), m_Zeros(zeros)
{
}
