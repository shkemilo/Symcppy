#include "Function.h"
#include <sstream>

Function::Function(const std::string& rawFunction, char functionVariable): m_RawFunction(rawFunction), m_FunctionVariable(functionVariable), m_Analyzer(rawFunction)
{
	if (!IsValidFunction())
	{
		// throw some error if it is not valid...
	}
}

void Function::SetFunctionRaw(const std::string& functionString, char functionVariable ='x')
{
	m_RawFunction = functionString;
	m_Analyzer.SetFunction(m_RawFunction);
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
	Union u;
	GetDomain(u);
	EParity parity;
	GetParity(parity);
	double period;
	EStatus periodStatus = GetPeriodicity(period);
	std::vector<double> zeros;
	GetZeros(zeros);
	Function derrivative;
	GetDerivative(derrivative);
	double min;
	EStatus minStatus = GetMin(min);
	double max;
	EStatus maxStatus = GetMax(max);
	Union* monotonicity = nullptr;
	GetMonotonicity(monotonicity);
	Union* convexity = nullptr;
	GetConvexity(convexity);

	return AnalysisDescription(*this, u, periodStatus, period, parity, derrivative, minStatus, min, maxStatus, max, monotonicity, convexity, zeros);
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
		out.SetFunctionRaw(*(static_cast<std::string*>(temp.value)));
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

EStatus Function::GetLimitAt(double point, ELimitFrom from, double& out) const
{
	FunctionResult temp = m_Analyzer.Limit(point, from);
	if (temp.result == EStatus::Sucess || temp.result == EStatus::MathInf)
	{
		out = *(static_cast<double*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetMin(double& out) const
{
	FunctionResult temp = m_Analyzer.GetMin();
	if (temp.result == EStatus::Sucess || temp.result == EStatus::MathInf)
	{
		out = *(static_cast<double*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetMax(double& out) const
{
	FunctionResult temp = m_Analyzer.GetMax();
	if (temp.result == EStatus::Sucess || temp.result == EStatus::MathInf)
	{
		out = *(static_cast<double*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetParity(EParity& out) const
{
	FunctionResult temp = m_Analyzer.GetParity();
	if (temp.result == EStatus::Sucess || temp.result == EStatus::MathInf)
	{
		out = (EParity)*(static_cast<int*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetMonotonicity(Union*& out) const
{
	FunctionResult temp = m_Analyzer.GetMonotonicity();
	if (temp.result == EStatus::Sucess)
	{
		out = static_cast<Union*>(temp.value);
	}
	return temp.result;
}

EStatus Function::GetConvexity(Union*& out) const
{
	FunctionResult temp = m_Analyzer.GetConvexity();
	if (temp.result == EStatus::Sucess)
	{
		out = static_cast<Union*>(temp.value);
	}
	return temp.result;
}

EStatus Function::GetPeriodicity(double& out) const
{
	FunctionResult temp = m_Analyzer.GetPeriodicity();
	if (temp.result == EStatus::Sucess || temp.result == EStatus::MathInf)
	{
		out = *(static_cast<double*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetDomain(Union& out) const
{
	FunctionResult temp = m_Analyzer.GetDomain();
	if (temp.result == EStatus::Sucess)
	{
		out = *(static_cast<Union*>(temp.value));
	}
	return temp.result;
}

EStatus Function::Plot() const
{
	FunctionResult temp = m_Analyzer.Plot();

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
