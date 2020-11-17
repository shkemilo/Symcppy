#include "Module.h"

#include "Helpers/Utils.h"
#include "FunctionDescriptor.h"

std::string Module::GetName() const
{
    return m_Name;
}

FunctionResult Module::CallFunction(FunctionIndex functionIndex, ArgCount argCount, va_list& args) const
{
    const FunctionDescriptor* function = m_Functions[functionIndex];
    return (function == nullptr ? FunctionResult{ EStatus::UndefinedFunction, nullptr } : function->Run(argCount, args));
}

PyObject* Module::GetPythonModule() const
{
    return m_PythonModule;
}

Module::~Module()
{
    while (!m_Functions.empty())
    {
        const FunctionDescriptor* function = m_Functions.back();
        m_Functions.pop_back();
        delete function;
    }
}

Module::Module(const std::string& name) : m_Name(name)
{
    PyObject* moduleName = PyUnicode_FromString(m_Name.c_str());
    m_PythonModule = PyImport_Import(moduleName);
}

/*
void Module::AddFunction(const FunctionDescriptor* function,EFunction typeOfFunction)
{
    if (std::find(m_Functions.begin(), m_Functions.end(), function) == m_Functions.end())
    {
        return;
    }

    m_Functions.push_back(function);
}
*/