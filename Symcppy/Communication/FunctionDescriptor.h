#pragma once
#include <string>
#include <vector>
#include <Python.h>

#include "Helpers/Utils.h"

class Module;

class FunctionDescriptor
{
public:
	FunctionDescriptor(const Module* owner, const std::string& name, ArgCount argCount);

	FunctionResult Run(ArgCount argCount, va_list& args) const;

	std::string GetName() const;

	virtual ~FunctionDescriptor() { };

protected:
	virtual bool CheckValidArgTypes(ArgCount argCount, va_list& args) const { return true; }
	virtual PyObject* PrepeareArguments(ArgCount, va_list& args) const = 0;
	virtual FunctionResult ConvertResult(PyObject* result) const = 0;

    const ArgCount m_ArgCount;
	std::vector<std::string> m_ArgTypes;

	const Module* m_OwnerModule;
	PyObject* m_PythonFunction;

private:
	const std::string m_Name;

};

