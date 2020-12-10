#include "Function.h"

Function::Function(const std::string& rawFunction, char variable):m_RawFunction(rawFunction),m_FunctionVariable(variable),m_Analyzer(rawFunction)
{
}

void Function::SetFunctionRaw(const std::string& fun, char funVar)
{
	m_RawFunction = fun;
	m_FunctionVariable = funVar;
}

std::string Function::GetFunctionRaw() const
{
	return m_RawFunction;
}

char Function::GetFunctionVariable() const
{
	return m_FunctionVariable;
}

EStatus Function::GetZeros(std::vector<double>& zeros) const
{
	FunctionResult temp = m_Analyzer.GetZeroes();
	if(temp.result==EStatus::Sucess)
	{
		zeros = *(static_cast<std::vector<double>*>(temp.value));
	}
	return temp.result;
}

EStatus Function::GetDerivative(Function& out)
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



Function operator+(Function arg1, Function arg2)
{
	std::string RawFunctionSum = arg1.m_RawFunction.append("+").append(arg2.m_RawFunction);
	return Function(RawFunctionSum, arg1.m_FunctionVariable);
}

Function operator-(Function arg1, Function arg2)
{
	std::string RawFunctionSub = arg1.m_RawFunction.append("-").append(arg2.m_RawFunction);
	return Function(RawFunctionSub, arg1.m_FunctionVariable);
}

Function operator*(Function arg1, Function arg2)
{
	std::string RawFunctionMul = arg1.m_RawFunction.append("*").append(arg2.m_RawFunction);
	return Function(RawFunctionMul, arg1.m_FunctionVariable);
}

Function operator/(Function arg1, Function arg2)
{
	std::string RawFunctionDiv = arg1.m_RawFunction.append("/").append(arg2.m_RawFunction);
	return Function(RawFunctionDiv, arg1.m_FunctionVariable);
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
