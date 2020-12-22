#pragma once

enum class EStatus
{
	Sucess = 0,
	MathInf,
	MathUndefined,
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

enum EMonotonicity
{
	Decreasing = 0,
	Increasing = 1
};

enum EConvexity
{
	Convex = 0,
	Concave = 1
};

enum EParity
{
	None = 0,
	Odd = 1,
	Even = 2,
};

enum ELimitFrom
{
	Left = 0,
	Point,
	Right,
};