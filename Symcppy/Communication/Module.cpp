#include "Module.h"

std::string Module::GetName() const
{
    return m_Name;
}

FunctionResult Module::CallFunction(FunctionIndex functionIndex, ArgCount argCount, const va_list& args) const
{
    const FunctionDescriptor* function = m_Functions[functionIndex];
    return (function == nullptr ? FunctionResult{ EStatus::UndefinedFunction, nullptr } : function->Run(argCount, args));
}

void Module::AddFunction(const FunctionDescriptor* function)
{
    if (std::find(m_Functions.begin(), m_Functions.end(), function) == m_Functions.end())
        return;

    m_Functions.push_back(function);
}
