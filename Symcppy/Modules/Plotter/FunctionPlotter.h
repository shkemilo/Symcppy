#pragma once
#include "Communication/Module.h"

class FunctionPlotter : public Module
{
public:
	enum EFunction
	{
		Plot = 0,
		Count,
		Invalid
	};

	FunctionPlotter();

	EModule GetModuleEnum() const override;

};

