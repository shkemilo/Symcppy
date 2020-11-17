#include "FunctionDescriptor.h"
#include <stdarg.h>

#include "Module.h"

FunctionDescriptor::FunctionDescriptor(const Module* owner, const std::string& name, ArgCount argCount) : 
    m_OwnerModule(owner), m_Name(name), m_ArgCount(argCount)
{
    m_PythonFunction = PyObject_GetAttrString(m_OwnerModule->GetPythonModule(), m_Name.c_str());
}

FunctionResult FunctionDescriptor::Run(ArgCount argCount,va_list& args) const
{
    if (argCount != m_ArgCount)
    {
        return FunctionResult{ EStatus::InvalidArgCount, nullptr };
    } 
    if (!checkValidArgTypes(argCount, args))
    {
        return FunctionResult{ EStatus::InvalidArgTypes, nullptr };
    }   

    PyObject* pythonArgs = PrepeareArguments(argCount, args);
    PyObject* pythonResult = PyObject_CallObject(m_PythonFunction, pythonArgs);

    return ConvertResult(pythonResult);
}

std::string FunctionDescriptor::GetName() const
{
    return m_Name;
}
