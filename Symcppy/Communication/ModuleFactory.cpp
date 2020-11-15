#include "ModuleFactory.h"
#include<memory>

#include "Modules/CalculusSolver/CalculusSolver.h"
#include "Modules/Solver/Solver.h"

// Modules can't be instantiated from their own constructors, 
// so when you add your own module make sure you add it here,
// format: return std::make_unique<YourModule>(name)
std::unique_ptr<Module> ModuleFactory::CreateModule(EModule module)
{
	switch (module)
	{
	case EModule::Solver:
		return std::make_unique<Solver>("Solver");
	case EModule::CalculusSolver:
		return std::make_unique<CalculusSolver>("CalculusSolver");
	default:
		return nullptr;
	}
}
