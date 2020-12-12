#include "PyManager.h"
#include <stdarg.h>

#include "ModuleFactory.h"
#include "Module.h"

PyManager* PyManager::ms_Instance{ nullptr };

PyManager::PyManager() : m_Modules(static_cast<int>(EModule::Count)) 
{
    for (int i = 0; i < static_cast<int>(EModule::Count); i++)
    {
        AddModule(static_cast<EModule>(i));
    }

    Py_Initialize(); 
}

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
    const Module* mod = GetModule(module);
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

const Module* PyManager::GetModule(EModule module) const
{
    if (module >= EModule::Count)
    {
        return nullptr;
    }

    return m_Modules[static_cast<int>(module)].get();
}

void PyManager::AddModule(EModule module)
{
    if (module >= EModule::Count || m_Modules[static_cast<int>(module)] != nullptr)
    {
        return;
    }
    
    m_Modules[static_cast<int>(module)] = std::move(ModuleFactory::CreateModule(module));
}