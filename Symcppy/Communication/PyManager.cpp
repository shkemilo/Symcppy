#include "PyManager.h"
#include <stdarg.h>

PyManager* PyManager::ms_Instance{ nullptr };

PyManager* PyManager::GetInstance()
{
    if (ms_Instance == nullptr)
    {
        ms_Instance = new PyManager();
    }

    return ms_Instance;
}

FunctionResult PyManager::CallFunction(EModule module, FunctionIndex functionIndex, ArgCount argCount, ...) const
{
    Module* mod = GetModule(module);
    if (mod == nullptr)
        return FunctionResult{ EStatus::UndefinedModule, nullptr };

    va_list args;
    va_start(args, argCount);
    FunctionResult result = mod->CallFunction(functionIndex, argCount, args);
    va_end(args);

    return result;
}

Module* PyManager::GetModule(EModule module) const
{
    return m_Modules[static_cast<int>(module)];
}

void PyManager::AddModule(Module* module)
{
    if (std::find(m_Modules.begin(), m_Modules.end(), module) == m_Modules.end())
        return;

    m_Modules.push_back(module);
}
