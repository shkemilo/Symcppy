#pragma once
#include <vector>
#include <memory>
#include <Python.h>

#include "Module.h"
#include "Helpers/PyEnums.h"
#include "Helpers/Utils.h"

class PyManager
{
public:
	PyManager(PyManager&) = delete;
	PyManager& operator=(PyManager&) = delete;

	static PyManager* GetInstance();

	FunctionResult CallFunction(EModule module, FunctionIndex functionIndex, ArgCount argCount, ...) const;

	const Module* GetModule(EModule module) const;
	void AddModule(EModule module);

private:
	PyManager() : m_Modules(static_cast<int>(EModule::Count)) { Py_Initialize(); };
	~PyManager() { Py_Finalize(); }

	static PyManager* ms_Instance;

	std::vector<std::unique_ptr<Module>> m_Modules;

};
