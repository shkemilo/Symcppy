#pragma once
#include"Communication/FunctionDescriptor.h"

class FunctionZeroes:public FunctionDescriptor
{
public:
	FunctionZeroes();
	~FunctionZeroes();
protected:
	bool checkValidArgTypes(ArgCount,va_list&) const override;
 	FunctionResult Execute(ArgCount argCount,va_list& args) const override;
private:
	static std::vector<std::string> argumentTypes;
};


class FunctionValueAt :public FunctionDescriptor
{
public:
	FunctionValueAt();
	~FunctionValueAt();
protected:
	bool checkValidArgTypes(ArgCount, va_list&) const override;
	FunctionResult Execute(ArgCount, va_list&) const override;
private:
	static std::vector<std::string> argumentTypes;
};

