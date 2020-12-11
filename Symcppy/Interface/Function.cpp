#include "Function.h"
#include <sstream>

Function::Function(const std::string& rawFunction, char functionVariable): m_RawFunction(rawFunction), m_FunctionVariable(functionVariable), m_Analyzer(rawFunction)
{
	if (!IsValidFunction())
	{
		// throw some error if it is not valid...
	}
}

void Function::SetFunctionRaw(const std::string& functionString, char functionVariable)
{
	m_RawFunction = functionString;
	m_FunctionVariable = functionVariable;
}

std::string Function::GetFunctionRaw() const
{
	return m_RawFunction;
}

char Function::GetFunctionVariable() const
{
	return m_FunctionVariable;
}

AnalysisDescription Function::GetAnalysis() const
{
	std::vector<double> zeros;
	GetZeros(zeros);
	Function derrivative;
	GetDerivative(derrivative);

	return AnalysisDescription(*this, derrivative, zeros);
}

EStatus Function::GetZeros(std::vector<double>& zeros) const
{
	FunctionResult temp = m_Analyzer.GetZeros();
	if(temp.result==EStatus::Sucess)
	{
		zeros = *(static_cast<std::vector<double>*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetDerivative(Function& out) const
{
	FunctionResult temp = m_Analyzer.Derrivative();
	if (temp.result == EStatus::Sucess) 
	{
		out.m_RawFunction = *(static_cast<std::string*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetValueAt(double point, double& out) const
{
	FunctionResult temp = m_Analyzer.ValueAt(point);
	if (temp.result == EStatus::Sucess)
	{
		out = *(static_cast<double*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetLimitAt(double point, double& out) const
{
	FunctionResult temp = m_Analyzer.Limit(point);
	if (temp.result == EStatus::Sucess)
	{
		out = *(static_cast<double*>(temp.value));
	}
	return temp.result;
}

bool Function::IsValidFunction() const
{
	return true;
}

Function Function::mergeWithSeperator(const Function& arg1, const Function& arg2, const std::string& seperator)
{
	std::stringstream functionStream;
	functionStream << "(" << arg1.GetFunctionRaw() << ")"
		<< seperator
		<< "(" << arg2.GetFunctionRaw() << ")";
	return Function(functionStream.str(), arg1.GetFunctionVariable());
}

Function operator+(const Function& arg1, const Function& arg2)
{
	return Function::mergeWithSeperator(arg1, arg2, " + ");
}

Function operator-(const Function& arg1, const Function& arg2)
{
	return Function::mergeWithSeperator(arg1, arg2, " - ");
}

Function operator*(const Function& arg1, const Function& arg2)
{
	return Function::mergeWithSeperator(arg1, arg2, " * ");
}

Function operator/(const Function& arg1, const Function& arg2)
{
	return Function::mergeWithSeperator(arg1, arg2, " / ");
}

std::ostream& operator<<(std::ostream& output, const Function& function)
{
	return output << function.m_RawFunction;
}

std::istream& operator>>(std::istream& input, Function& function)
{
	input >> function.m_RawFunction;
	return input;
}
