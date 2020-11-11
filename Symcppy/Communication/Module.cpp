#include "Module.h"
#include "../Helpers/Utils.h"

std::string Module::GetName() const
{
    return m_Name;
}

FunctionResult Module::CallFunction(FunctionIndex functionIndex, ArgCount argCount,va_list& args) const
{
    const FunctionDescriptor* function = m_Functions[functionIndex];
    return (function == nullptr ? FunctionResult{ EStatus::UndefinedFunction, nullptr } : function->Run(argCount, args));
}
/*
void Module::AddFunction(const FunctionDescriptor* function,EFunction typeOfFunction)
{
    if (std::find(m_Functions.begin(), m_Functions.end(), function) == m_Functions.end())
        return;
    int placeToPut = static_cast<int>(typeOfFunction);
    m_Functions.insert(m_Functions.begin()+placeToPut, function);
} */
