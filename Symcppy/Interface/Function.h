#pragma once
#include <string>
#include <vector>

#include "Helpers/PyEnums.h"
#include "Helpers/Utils.h"
#include "FunctionAnalyzer.h"


class Function
{
public:
	Function(const std::string& rawFunction, char variable);

	void SetFunctionRaw(const std::string& fun, char funVar);

	std::string GetFunctionRaw() const;
	char GetFunctionVariable() const;
	
	EStatus GetZeros(std::vector<double>& zeros) const;
	EStatus GetDerivative(Function& out); //sve se vraca preko reference !!!
	EStatus GetValueAt(double point, double& out) const;
	EStatus GetLimitAt(double point, double& out) const;
	EStatus Plot(std::string dir) const;

	friend Function operator+(Function arg1, Function arg2); //arg umesto fun
	friend Function operator-(Function arg1, Function arg2);
	friend Function operator*(Function arg1, Function arg2);
	friend Function operator/(Function arg1, Function arg2);
	friend std::ostream& operator<<(std::ostream& output, const Function& function);
	friend std::istream& operator>>(std::istream& input,  Function& function);

protected:
	FunctionAnalyzer m_Analyzer;
	bool IsValidFunction(std::string rawFunction);

private:
	std::string m_RawFunction;
	char m_FunctionVariable;

};

