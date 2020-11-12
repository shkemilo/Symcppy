#include "FunctionDescriptor.h"
#include<stdarg.h>
FunctionDescriptor::FunctionDescriptor(const std::string& name, ArgCount argCount) : 
    m_Name(name), m_ArgCount(argCount)
{
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

    return Execute(argCount, args);
}

std::string FunctionDescriptor::GetName() const
{
    return m_Name;
}
