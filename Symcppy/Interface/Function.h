#pragma once
#include <string>
#include <vector>
#include <thread>

#include "Helpers/PyEnums.h"
#include "Helpers/Utils.h"
#include "FunctionAnalyzer.h"
#include "AnalysisDescription.h"

class Function
{
public:
	Function(const std::string& rawFunction = "", char functionVariable = 'x');

	void SetFunctionRaw(const std::string& functionString, char functionVariable);

	std::string GetFunctionRaw() const;
	char GetFunctionVariable() const;

	AnalysisDescription GetAnalysis() const;
	
	EStatus GetZeros(std::vector<double>& zeros) const;
	EStatus GetDerivative(Function& out) const;
	EStatus GetValueAt(double point, double& out) const;
	EStatus GetLimitAt(double point, ELimitFrom from, double& out) const;
	EStatus GetMin(double& out) const;
	EStatus GetMax(double& out) const;
	EStatus GetParity(EParity& out) const;
	EStatus GetMonotonicity(Union*& out) const;
	EStatus GetConvexity(Union*& out) const;
	EStatus GetPeriodicity(double& out) const;
	EStatus GetDomain(Union& out) const;
	EStatus Plot() const;

	friend Function operator+(const Function& arg1, const Function& arg2);
	friend Function operator-(const Function& arg1, const Function& arg2);
	friend Function operator*(const Function& arg1, const Function& arg2);
	friend Function operator/(const Function& arg1, const Function& arg2);
	friend std::ostream& operator<<(std::ostream& output, const Function& function);
	friend std::istream& operator>>(std::istream& input,  Function& function);

protected:
	bool IsValidFunction() const;

	FunctionAnalyzer m_Analyzer;

private:
	static Function mergeWithSeperator(const Function& arg1, const Function& arg2, const std::string& seperator);

	std::string m_RawFunction;
	char m_FunctionVariable;

};

