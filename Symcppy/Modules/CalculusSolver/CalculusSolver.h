#pragma once
#include"Communication/Module.h"

class CalculusSolver : public Module
{
public:
	enum EFunction
	{
		Derivate=0,
		Limit,
		Count,
		Invalid
	};

	CalculusSolver(const std::string& name);

	EModule GetModuleEnum() const override;

};

