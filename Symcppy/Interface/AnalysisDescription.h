#pragma once
#include <vector>

class Function;

class AnalysisDescription
{
public:
	AnalysisDescription(const Function& owner, const Function& derrivative, const std::vector<double>& zeros);

	const Function& GetOwner() const { return m_Owner; }
	const Function& GetDerrivative() const { return m_Derrivative; }
	const std::vector<double>& GetZeros() const { return m_Zeros; }

private:
	const Function& m_Owner;
	const Function& m_Derrivative;

	const std::vector<double>& m_Zeros;

};