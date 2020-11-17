#pragma once
#include <memory>

#include "Module.h"
#include "Helpers/PyEnums.h"

class ModuleFactory
{
public:
	static std::unique_ptr<Module> CreateModule(EModule module);

private:
	ModuleFactory() = default;

};