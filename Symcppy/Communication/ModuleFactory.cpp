#include "ModuleFactory.h"

// Modules can't be instantiated from their own constructors, 
// so when you add your own module make sure you add it here,
// format: return std::make_unique<YourModule>(name)
std::unique_ptr<Module> ModuleFactory::CreateModule(EModule module)
{
	switch (module)
	{
	case EModule::Test:
		return nullptr;
	default:
		return nullptr;
	}
}
