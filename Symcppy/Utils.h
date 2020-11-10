#pragma once
#include "PyEnums.h"

typedef unsigned int ArgCount;
typedef unsigned int FunctionIndex;

struct FunctionResult
{
	EStatus result{ EStatus::Error };
	void* value{ nullptr };
};


