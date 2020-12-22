#pragma once
#include <vector>

#include "Helpers/Utils.h"

class Function;

class AnalysisDescription
{
public:
	AnalysisDescription(const Function& owner, const Union& domain, EStatus periodStatus, double period, EParity parity, const Function& derrivative, EStatus minStatus, double min, EStatus maxStatus, double max, Union* monotonicity, Union* convexity, const std::vector<double>& zeros);

	const Function& GetOwner() const { return *m_Owner; }
	const Union& GetDomain() const { return m_Domain; }
	const double& GetPeriod() const { return m_PeriodStatus == EStatus::Sucess ? m_Period : 0; }
	const EParity& GetParity() const { return m_Parity; }
	const Function& GetDerrivative() const { return *m_Derrivative; }
	const double& GetMin() const { return m_MinStatus == EStatus::Sucess ? m_Min : K_NEGATIVE_INF_VALUE; }
	const double& GetMax() const { return m_MaxStatus == EStatus::Sucess ? m_Max : K_POSITIVE_INF_VALUE; }
	const Union* GetMonotonicity() const { return m_Monotonicity; }
	const Union* GetConvexity() const { return m_Convexity; }
	const std::vector<double>& GetZeros() const { return m_Zeros; }

	friend std::ostream& operator<<(std::ostream& os, const AnalysisDescription& ad);

	~AnalysisDescription();

private:
	static std::string ParityToString(const EParity parity);

	const Function* m_Owner;
	const Union m_Domain;
	const EStatus m_PeriodStatus;
	const double m_Period;
	const EParity m_Parity;
	const Function* m_Derrivative;
	const EStatus m_MinStatus;
	const double m_Min;
	const EStatus m_MaxStatus;
	const double m_Max;
	const Union* m_Monotonicity;
	const Union* m_Convexity;

	const std::vector<double> m_Zeros;
};