#include "SolverDescriptors.h"
#include<stdarg.h>

std::vector<std::string> FunctionValueAt::argumentTypes{ "string,double" };
std::vector<std::string> FunctionZeroes::argumentTypes{ "string" };
FunctionValueAt::FunctionValueAt() :FunctionDescriptor("FunctionValueAt", 2, FunctionValueAt::argumentTypes) { }


bool FunctionValueAt::checkValidArgTypes(ArgCount argCount,va_list& args) const
{
	va_start(args, this->m_ArgCount);
	std::string checker = "string";
	if (checker != va_arg(args, std::string))
	{
		checker = "double";
		if (checker != va_arg(args, std::string))
		{
			va_end(args);
			return true;
		}
		else
		{
			va_end(args);
			return false;
		}
	}
	else
	{
		va_end(args);
		return false;
	}
}

FunctionResult FunctionValueAt::Execute(ArgCount argCount,va_list& args) const
{
	if (!this->checkValidArgTypes(argCount, args)) return FunctionResult{ EStatus::Error,nullptr };
	else
	{
		//function execution in Python
	}
}

FunctionValueAt::~FunctionValueAt()
{

}

FunctionZeroes::FunctionZeroes() :FunctionDescriptor("FunctionZeroes", 1, FunctionZeroes::argumentTypes)
{
}

FunctionZeroes::~FunctionZeroes()
{

}

bool FunctionZeroes::checkValidArgTypes(ArgCount argCount, va_list& args) const
{
	va_start(args, argCount);
	bool ret = false;
	if (va_arg(args, std::string) == "string") ret = true;
	va_end(args);
	return ret;
}

FunctionResult FunctionZeroes::Execute(ArgCount argCount, va_list& args) const
{
	if (!this->checkValidArgTypes(argCount, args)) return FunctionResult{EStatus::Error,nullptr};
	else
	{
		//function execution in Python
	}
}

