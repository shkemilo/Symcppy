#include "FunctionDescriptor.h"
#include <stdarg.h>

#include "Module.h"

FunctionDescriptor::FunctionDescriptor(const Module* owner, const std::string& name, ArgCount argCount) : 
    m_OwnerModule(owner), m_Name(name), m_ArgCount(argCount)
{
    m_PythonFunction = PyObject_GetAttrString(m_OwnerModule->GetPythonModule(), m_Name.c_str());
    if (!m_PythonFunction)
    {
        PyErr_Print();
    }
}

FunctionResult FunctionDescriptor::Run(ArgCount argCount,va_list& args) const
{
    if (argCount != m_ArgCount)
    {
        return FunctionResult{ EStatus::InvalidArgCount, nullptr };
    } 
    if (!CheckValidArgTypes(argCount, args))
    {
        return FunctionResult{ EStatus::InvalidArgTypes, nullptr };
    }   

    PyObject* pythonArgs = PrepareArguments(argCount, args);
    if (!pythonArgs)
    {
#ifdef _DEBUG
        PyErr_Print();
#endif // !_DEBUG
        return FunctionResult{ EStatus::Error, nullptr };
    }
    PyObject* pythonResult = PyObject_CallObject(m_PythonFunction, pythonArgs);
    if (!pythonResult)
    {
#ifdef _DEBUG
        PyErr_Print();
#endif // !_DEBUG
        return FunctionResult{ EStatus::Error, nullptr };
    }

    return ConvertResult(pythonResult);
}

std::string FunctionDescriptor::GetName() const
{
    return m_Name;
}
