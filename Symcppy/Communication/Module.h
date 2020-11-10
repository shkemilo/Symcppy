#pragma once
#include <string>
#include <vector>

#include"../Helpers/PyEnums.h"
#include "FunctionDescriptor.h"

class Module
{
public:
	enum EFunction
	{
		Invalid=0,
		Solver,
		FunctionPlotter,
		CalculusSolver,
		Count
	};

	virtual EModule GetModuleEnum() const = 0;
	std::string GetName() const;

	FunctionResult CallFunction(FunctionIndex functionIndex, ArgCount argCount, const va_list& args) const;

protected:
	Module(const std::string& name) : m_Name(name) { }
	virtual ~Module() { };

	void AddFunction(const FunctionDescriptor* function,EFunction typeOfFunction);

private:
	const std::string m_Name;

	std::vector<const FunctionDescriptor*> m_Functions;

};

