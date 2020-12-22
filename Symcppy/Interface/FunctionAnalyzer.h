#pragma once
#include "Communication/PyManager.h"
#include "Helpers/Utils.h"

class FunctionAnalyzer
{
public:
	FunctionAnalyzer(const std::string& function);

	void SetFunction(const std::string& function) { m_Function = function; }

	FunctionResult Plot() const;

	FunctionResult GetDomain() const;
	FunctionResult GetPeriodicity() const;
	FunctionResult GetParity() const;
	FunctionResult GetMin() const;
	FunctionResult GetMax() const;
	FunctionResult GetMonotonicity() const;
	FunctionResult GetConvexity() const;
	FunctionResult Derrivative() const;
	FunctionResult Limit(double point, ELimitFrom from) const;

	FunctionResult ValueAt(double point) const;
	FunctionResult GetZeros() const;

private:
	std::string m_Function;

};