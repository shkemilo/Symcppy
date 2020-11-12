#include "PyManager.h"
#include <stdarg.h>

#include "ModuleFactory.h"

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
    {
        return FunctionResult{ EStatus::UndefinedModule, nullptr };
    }

    va_list args;
    va_start(args, argCount);
    FunctionResult result = mod->CallFunction(functionIndex, argCount, args);
    va_end(args);

    return result;
}

Module* PyManager::GetModule(EModule module) const
{
    if (module >= EModule::Count)
    {
        return nullptr;
    }

    return m_Modules[static_cast<int>(module)].get();
}

void PyManager::AddModule(EModule module)
{
    std::unique_ptr<Module> mod = std::move(ModuleFactory::CreateModule(module));
    if (std::find(m_Modules.begin(), m_Modules.end(), mod) == m_Modules.end())
    {
        return;
    }

    m_Modules.push_back(std::move(mod));
}