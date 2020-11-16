#pragma once

enum class EStatus
{
	Sucess = 0,
	MathError,
	Error,
	UndefinedModule,
	UndefinedFunction,
	InvalidArgCount,
	InvalidArgTypes,
	Count,
	Invalid
};

enum class EModule
{
	Solver = 0,
	CalculusSolver,
	FunctionPlotter,
	Count,
	Invalid
};