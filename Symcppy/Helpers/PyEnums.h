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
	Test = 0,
	FunctionModules,
	Count,
	Invalid
};