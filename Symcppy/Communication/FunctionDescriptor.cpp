#include "FunctionDescriptor.h"

FunctionDescriptor::FunctionDescriptor(const std::string& name, ArgCount argCount, const std::vector<std::string>& argTypes) : 
    m_Name(name), m_ArgCount(argCount), m_ArgTypes(argTypes)
{
}

FunctionResult FunctionDescriptor::Run(ArgCount argCount, const va_list& args) const
{
    if (argCount != m_ArgCount)
        return FunctionResult{ EStatus::InvalidArgCount, nullptr };

    return Execute(argCount, args);
}

std::string FunctionDescriptor::GetName() const
{
    return m_Name;
}

bool FunctionDescriptor::checkValidArgTypes() const
{
    return true; // todo: implement
}
