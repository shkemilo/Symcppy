#pragma once
#include "Communication/Module.h"

#include "Helpers/PyEnums.h"

class Solver : public Module
{
public:
	enum EFunction
	{
		Zeros = 0,
		ValueAt,
		Count,
		Invalid
	};

	Solver();

	EModule GetModuleEnum() const override;
};
