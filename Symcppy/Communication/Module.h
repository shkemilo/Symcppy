#pragma once
#include <string>
#include <vector>
#include <Python.h>

#include "Helpers/PyEnums.h"
#include "Helpers/Utils.h"

class FunctionDescriptor;

class Module
{
	friend class ModuleFactory;

public:
	enum EFunction
	{
		Count = 0,
		Invalid
	};

	Module& operator=(Module&) = delete;

	virtual EModule GetModuleEnum() const = 0;
	std::string GetName() const;

	FunctionResult CallFunction(FunctionIndex functionIndex, ArgCount argCount, va_list& args) const;

	PyObject* GetPythonModule() const;

	virtual ~Module();

protected:
	Module(const std::string& name);

	void AddFunction(const FunctionDescriptor* function, EFunction typeOfFunction);

	std::vector<const FunctionDescriptor*> m_Functions;

	PyObject* m_PythonModule;

private:
	const std::string m_Name;

};

