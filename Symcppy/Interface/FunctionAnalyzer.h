#pragma once
#include "Communication/PyManager.h"
#include "Helpers/Utils.h"

class FunctionAnalyzer
{
public:
	FunctionAnalyzer(const std::string& function);

	FunctionResult Plot() const;

	FunctionResult Derrivative() const;
	FunctionResult Limit(double point) const;

	FunctionResult ValueAt(double point) const;
	FunctionResult GetZeroes() const;

private:
	const std::string& m_Function;

};