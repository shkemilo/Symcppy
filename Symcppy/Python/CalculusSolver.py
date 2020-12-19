from sympy import *
from sympy.calculus.util import continuous_domain, function_range

import numbers
import math

def IntervalToString(interval):
	return ("(" if interval.left_open else "[") + str(interval.left.evalf()) + ", " + str(interval.right.evalf()) + (")" if interval.right_open else "]")

def UnionToString(union):
	unionString = ""
	for interval in union.args:
		if(unionString != ""):
			unionString = unionString + "U"
		unionString = unionString + IntervalToString(interval)

	return unionString

def DomainToString(domain):
	if(isinstance(domain, Interval)):
		return IntervalToString(domain)
	elif(isinstance(domain, Union)):
		return UnionToString(domain)
	else:
		return ""


def convertExpressionList(expressionList):
	numberList = []
	for expression in expressionList:
		numberList.append(expression.evalf())
	return numberList

def GetDerivative(function):
    x = symbols('x', real = True)
    f = eval(function)
    d = diff(f, x)
    return str(d)


def GetLimit(function, point, sign):
    x = symbols('x', real = True)
    f = eval(function)
    if sign == '':
        l = limit(f, x, point)
    else:
        l = limit(f, x, point, sign)
    
    if isinstance(l, numbers.Number):
        if not math.isinf(l):
            return float(l)
        else:
            return str(l)
    else:
        return 'None'


def GetMin(function):
    x = symbols('x', real = True)
    f = eval(function)
    m = minimum(f, x, S.Reals)
    
    if isinstance(m, numbers.Number) and not math.isinf(m):
        return float(m)
    else:
        return 'None'

def GetMax(function):
    x = symbols('x', real = True)
    f = eval(function)
    m = maximum(f, x, S.Reals)
    
    if isinstance(m, numbers.Number) and not math.isinf(m):
        return float(m)
    else:
        return 'None'



def GetDomain(function):
    x = symbols('x', real = True)
    f = eval(function)
    domain = continuous_domain(f, x, S.Reals)
    return DomainToString(domain)



def GetPeriodicity(function):
    x = symbols('x', real = True)
    f = eval(function)
    p = periodicity(f,x)
    if p == None or p == 0:
        return 'Aperiodic'
    else:
        return str(p)


############################### IN PROGRESS ... ###############################

def GetSymmetry(function):
    x = Symbol('x', real = True)
   # x = symbols('x')
    f = Function(function)
    result = f - f.subs(x, -x)

    if  result == 0:
        return 2
    elif result == (2*f):
        return 1
    else:
        return 0
    

 ###############################################################################   


def CheckMonotonicity(fun):
    x = symbols('x', real = True)
    f = eval(fun)
    domain = continuous_domain(f, x, S.Reals)
    union_increasing = Union()
    union_decreasing = Union()
    if isinstance(domain, Interval):
        if is_increasing(f, domain, x):
            union_increasing = Union(union_increasing, domain)
        else:
            union_decreasing = Union(union_decreasing, domain)
    else:
        for i in domain.args:
            if is_increasing(f, i, x):
                union_increasing = Union(union_increasing, i)
            else:
                union_decreasing = Union(union_decreasing, i)

    return (DomainToString(union_increasing), DomainToString(union_decreasing))




