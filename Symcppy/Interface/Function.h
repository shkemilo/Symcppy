#pragma once
#include <string>
#include <vector>

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
	EStatus GetLimitAt(double point, double& out) const;
	EStatus Plot(const std::string& dir) const;

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

