#include "AnalysisDescription.h"
#include <iostream>

#include "Function.h"

AnalysisDescription::AnalysisDescription(const Function& owner, const Union& domain, EStatus periodStatus, double period, EParity parity, const Function& derrivative, EStatus minStatus, double min, EStatus maxStatus, double max, Union* monotonicity, Union* convexity, const std::vector<double>& zeros) :
	m_Zeros(zeros), m_Domain(domain),
	m_PeriodStatus(periodStatus), m_Period(period),
	m_Parity(parity),
	m_MinStatus(minStatus), m_Min(min), 
	m_MaxStatus(maxStatus), m_Max(max),
	m_Monotonicity(monotonicity), m_Convexity(convexity)
{
	m_Owner = new Function(owner);
	m_Derrivative = new Function(derrivative);
}

AnalysisDescription::~AnalysisDescription()
{
	delete m_Owner;
	delete m_Derrivative;
}

std::string AnalysisDescription::ParityToString(const EParity parity)
{
	switch (parity)
	{
	case EParity::None:
		return "None";
	case EParity::Even:
		return "Even";
	case EParity::Odd:
		return "Odd";
	default:
		return "None";
	}
}

std::ostream& operator<<(std::ostream& os, const AnalysisDescription& ad)
{
	os << "Function: " << ad.GetOwner().GetFunctionRaw() << std::endl
		<< "Domain: " << ad.GetDomain() << std::endl
		<< "Parity: " << AnalysisDescription::ParityToString(ad.GetParity()) << std::endl
		<< "Periodicity: " << ((ad.m_PeriodStatus == EStatus::Sucess) ? std::to_string(ad.GetPeriod()) : "Undefined") << std::endl
		<< "Zeros: ";
	for (double zero : ad.GetZeros())
	{
		os << zero << " ";
	}
	os << std::endl
		<< "Derivative: " << ad.GetDerrivative().GetFunctionRaw() << std::endl
		<< "Min: " << ((ad.m_MinStatus == EStatus::Sucess) ? std::to_string(ad.GetMin()) : "Undefined") << std::endl
		<< "Max: " << ((ad.m_MaxStatus == EStatus::Sucess) ? std::to_string(ad.GetMax()) : "Undefined") << std::endl
		<< "Decreasing: " << ad.GetMonotonicity()[EMonotonicity::Decreasing] << std::endl
		<< "Increasing: " << ad.GetMonotonicity()[EMonotonicity::Increasing] << std::endl
		<< "Concave: " << ad.GetConvexity()[EConvexity::Concave] << std::endl
		<< "Convex: " << ad.GetConvexity()[EConvexity::Convex] << std::endl;
	return os;
}
