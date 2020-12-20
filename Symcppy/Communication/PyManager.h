#pragma once
#include <string>
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

	void AddModulePath(const std::string& modulePath) const;
	const Module* GetModule(EModule module) const;
	void AddModule(EModule module);

private:
	PyManager();
	~PyManager() { Py_Finalize(); }

	static PyManager* ms_Instance;

	std::vector<std::unique_ptr<Module>> m_Modules;

};
