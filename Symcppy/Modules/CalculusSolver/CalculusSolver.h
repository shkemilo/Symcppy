#pragma once
#include"Communication/Module.h"

class CalculusSolver : public Module
{
public:
	enum EFunction
	{
		Derivative = 0,
		Limit,
		Minimum,
		Maximum,
		Periodicity,
		Domain,
		Parity,
		Monotonicity,
		Convexity,
		Count,
		Invalid
	};

	CalculusSolver();

	EModule GetModuleEnum() const override;

};

