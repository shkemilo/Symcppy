#pragma once
#include <vector>

#include "Module.h"
#include "../Helpers/PyEnums.h"
#include "../Helpers/Utils.h"

class PyManager
{
public:
	PyManager(PyManager&) = delete;
	void operator=(PyManager&) = delete;

	static PyManager* GetInstance();

	FunctionResult CallFunction(EModule module, FunctionIndex functionIndex, ArgCount argCount, ...) const;

	Module* GetModule(EModule module) const;
	void AddModule(Module* module);

private:
	PyManager() { };

	static PyManager* ms_Instance;
	std::vector<Module*> m_Modules;

};
