#include "CalculusSolverDescriptors.h"
#include <iostream>
#include <string>
#include <stdarg.h>

// Class: FunctionDerivative
FunctionDerivative::FunctionDerivative(Module* owner) : FunctionDescriptor(owner, "GetDerivative", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionDerivative::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionDerivative::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionDerivative::ConvertResult(PyObject* result) const
{
	std::string* function = new std::string((PyUnicode_AsUTF8(result)));
	EStatus status = function != nullptr ? EStatus::Sucess : EStatus::Error;

	return FunctionResult{ status, (void*)(function) };
}

// Class: FunctionLimit
FunctionLimit::FunctionLimit(Module* owner) : FunctionDescriptor(owner, "GetLimit", 3)
{
	m_ArgTypes.push_back("string");
	m_ArgTypes.push_back("double");
}

bool FunctionLimit::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionLimit::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	double point = va_arg(args, double);
	PyObject* pyPoint = PyFloat_FromDouble(point);

	ELimitFrom from = va_arg(args, ELimitFrom);
	PyObject* pyFrom = PyUnicode_FromString(LimitFromToSign(from).c_str());

	return PyTuple_Pack(3, pyFunction, pyPoint, pyFrom);
}

FunctionResult FunctionLimit::ConvertResult(PyObject* result) const
{
	FunctionResult functionResult;
	if (PyFloat_Check(result))
	{
		functionResult.value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
		functionResult.result = EStatus::Sucess;
	}
	else if (PyUnicode_Check(result))
	{
		const char* message = PyUnicode_AsUTF8(result);
		if (message == K_POSITIVE_INF)
		{
			functionResult.result = EStatus::MathInf;
			functionResult.value = new double(K_POSITIVE_INF_VALUE);
		}
		else if (message == K_NEGATIVE_INF)
		{
			functionResult.result = EStatus::MathInf;
			functionResult.value = new double(K_NEGATIVE_INF_VALUE);
		}
		else
		{
			functionResult.result = EStatus::MathUndefined;
		}
	}

	return functionResult;
}

std::string FunctionLimit::LimitFromToSign(ELimitFrom from)
{
	switch (from)
	{
	case ELimitFrom::Left:
		return "-";
	case ELimitFrom::Point:
		return "";
	case ELimitFrom::Right:
		return "+";
	default:
		return "";
	}
}

// Class: FunctionMinimum
FunctionMinimum::FunctionMinimum(Module* owner) : FunctionDescriptor(owner, "GetMin", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionMinimum::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionMinimum::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionMinimum::ConvertResult(PyObject* result) const
{
	FunctionResult functionResult;
	if (PyFloat_Check(result))
	{
		functionResult.value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
		functionResult.result = EStatus::Sucess;
	}
	else if (PyUnicode_Check(result))
	{
		const char* message = PyUnicode_AsUTF8(result);
		if (message == "None")
		{
			functionResult.result = EStatus::MathUndefined;
		}
		else
		{
			functionResult.result = EStatus::Error;
		}
	}

	return functionResult;
}

// Class: FunctionMaximum
FunctionMaximum::FunctionMaximum(Module* owner) : FunctionDescriptor(owner, "GetMax", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionMaximum::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionMaximum::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionMaximum::ConvertResult(PyObject* result) const
{
	FunctionResult functionResult;
	if (PyFloat_Check(result))
	{
		functionResult.value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
		functionResult.result = EStatus::Sucess;
	}
	else if (PyUnicode_Check(result))
	{
		const char* message = PyUnicode_AsUTF8(result);
		if (message == "None")
		{
			functionResult.result = EStatus::MathUndefined;
		}
		else
		{
			functionResult.result = EStatus::Error;
		}
	}

	return functionResult;
}

// Class: FunctionPeriodicity
FunctionPeriodicity::FunctionPeriodicity(Module* owner) : FunctionDescriptor(owner, "GetPeriodicity", 1)
{
	m_ArgTypes.push_back("string");
}

bool FunctionPeriodicity::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionPeriodicity::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionPeriodicity::ConvertResult(PyObject* result) const
{
	FunctionResult functionResult;
	if (PyFloat_Check(result))
	{
		functionResult.value = new double(PyFloat_AsDouble(result)); // NOTE: Memory should be released somehow
		functionResult.result = EStatus::Sucess;
	}
	else if (PyUnicode_Check(result))
	{
		const char* message = PyUnicode_AsUTF8(result);
		if (message == "Aperiodic")
		{
			functionResult.result = EStatus::MathUndefined;
		}
	}

	return functionResult;
}

// Class: FunctionDomain
FunctionDomain::FunctionDomain(Module* owner) : FunctionDescriptor(owner, "GetDomain", 1)
{
}

bool FunctionDomain::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionDomain::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionDomain::ConvertResult(PyObject* result) const
{
	const char* domain = PyUnicode_AsUTF8(result);
	EStatus status = domain != nullptr ? EStatus::Sucess : EStatus::Error;

	Union* ret = domain != nullptr ? new Union(domain) : nullptr;
	return FunctionResult{ status, (void*)(ret) };
}

// Class: FunctionParity
FunctionParity::FunctionParity(Module* owner) : FunctionDescriptor(owner, "GetSymmetry", 1)
{
}

bool FunctionParity::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionParity::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionParity::ConvertResult(PyObject* result) const
{
	FunctionResult res;
	if (PyLong_Check(result))
	{
		res.value = new int(PyLong_AsLong(result));
		res.result = EStatus::Sucess;
	}

	return res;
}

// Class: FunctionMonotonicity
FunctionMonotonicity::FunctionMonotonicity(Module* owner) : FunctionDescriptor(owner, "CheckMonotonicity", 1)
{
}

bool FunctionMonotonicity::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionMonotonicity::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionMonotonicity::ConvertResult(PyObject* result) const
{
	FunctionResult res;

	PyObject* pyDecreasing = PyTuple_GetItem(result, EMonotonicity::Decreasing);
	if (!pyDecreasing || !PyUnicode_Check(pyDecreasing))
	{
		return res;
	}
	PyObject* pyIncreasing = PyTuple_GetItem(result, EMonotonicity::Increasing);
	if (!pyIncreasing || !PyUnicode_Check(pyIncreasing))
	{
		return res;
	}

	Union* u = new Union[2];
	u[EMonotonicity::Decreasing] = Union(PyUnicode_AsUTF8(pyDecreasing));
	u[EMonotonicity::Increasing] = Union(PyUnicode_AsUTF8(pyIncreasing));

	res.result = EStatus::Sucess;
	res.value = (void*)u;
	return res;
}

// Class: FunctionConvexity
FunctionConvexity::FunctionConvexity(Module* owner) : FunctionDescriptor(owner, "GetConvexity", 1)
{
}

bool FunctionConvexity::CheckValidArgTypes(ArgCount argCount, va_list& args) const
{
	return true;
}

PyObject* FunctionConvexity::PrepareArguments(ArgCount argCount, va_list& args) const
{
	const char* function = va_arg(args, const char*);
	PyObject* pyFunction = PyUnicode_FromString(function);

	return PyTuple_Pack(1, pyFunction);
}

FunctionResult FunctionConvexity::ConvertResult(PyObject* result) const
{
	FunctionResult res;

	PyObject* pyConcave = PyTuple_GetItem(result, EConvexity::Concave);
	if (!pyConcave || !PyUnicode_Check(pyConcave))
	{
		return res;
	}
	PyObject* pyConvex = PyTuple_GetItem(result, EConvexity::Convex);
	if (!pyConvex || !PyUnicode_Check(pyConvex))
	{
		return res;
	}

	Union* u = new Union[2];
	u[EConvexity::Concave] = Union(PyUnicode_AsUTF8(pyConcave));
	u[EConvexity::Convex] = Union(PyUnicode_AsUTF8(pyConvex));

	res.result = EStatus::Sucess;
	res.value = (void*)u;
	return res;
}
