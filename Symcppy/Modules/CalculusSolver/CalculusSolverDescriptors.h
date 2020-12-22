#pragma once
#include "Communication/FunctionDescriptor.h"

class FunctionDerivative : public FunctionDescriptor
{
public:
	FunctionDerivative(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionLimit : public FunctionDescriptor
{
public:
	FunctionLimit(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

private:
	static std::string LimitFromToSign(ELimitFrom from);

};

class FunctionDomain : public FunctionDescriptor
{
public:
	FunctionDomain(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionMinimum : public FunctionDescriptor
{
public:
	FunctionMinimum(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionMaximum : public FunctionDescriptor
{
public:
	FunctionMaximum(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionPeriodicity : public FunctionDescriptor
{
public:
	FunctionPeriodicity(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionParity : public FunctionDescriptor
{
public:
	FunctionParity(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionMonotonicity : public FunctionDescriptor
{
public:
	FunctionMonotonicity(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};

class FunctionConvexity : public FunctionDescriptor
{
public:
	FunctionConvexity(Module* owner);

protected:
	bool CheckValidArgTypes(ArgCount argCount, va_list& args) const override;
	PyObject* PrepareArguments(ArgCount argCount, va_list& args) const override;
	FunctionResult ConvertResult(PyObject* result) const override;

};