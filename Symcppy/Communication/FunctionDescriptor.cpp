#include "FunctionDescriptor.h"
#include<stdarg.h>
FunctionDescriptor::FunctionDescriptor(const std::string& name, ArgCount argCount) : 
    m_Name(name), m_ArgCount(argCount)
{
}

FunctionResult FunctionDescriptor::Run(ArgCount argCount,va_list& args) const
{
    if (argCount != m_ArgCount)
        return FunctionResult{ EStatus::InvalidArgCount, nullptr };
    else if (!this->checkValidArgTypes(argCount, args)) return FunctionResult{ EStatus::Invalid, nullptr };
    else return Execute(argCount, args);
}

std::string FunctionDescriptor::GetName() const
{
    return m_Name;
}

bool FunctionDescriptor::checkValidArgTypes(ArgCount argCount, va_list& args) const
{
    if (argCount != m_ArgCount) return false;
    va_start(args, argCount);
    for (int i = 0; i < argCount; i++)
    {
        if (m_ArgTypes.at(i) != (va_arg(args, std::string))) return false;
    }
    return true;
}
