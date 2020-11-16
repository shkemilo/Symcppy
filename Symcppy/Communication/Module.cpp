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

Module::~Module()
{
    while (!m_Functions.empty())
    {
        const FunctionDescriptor* function = m_Functions.back();
        m_Functions.pop_back();
        delete function;
    }
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