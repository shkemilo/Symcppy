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
    m = minimum(f, x, S.Reals).evalf()
    
    if isinstance(m, numbers.Number) and not math.isinf(m):
        return float(m)
    else:
        return 'None'

def GetMax(function):
    x = symbols('x', real = True)
    f = eval(function)
    m = maximum(f, x, S.Reals).evalf()

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
        return float(p)




def GetSymmetry(function):
    x = Symbol('x', real = True)
    f = eval(function)
    result = f - f.subs(x, -x)

    if  result == 0:
        return 2
    elif result == (2*f):
        return 1
    else:
        return 0
    

  

def GetConvexity(fun):
    x = symbols('x', real = True)
    f = eval(fun)
    f_diff = diff(f, x)
    f_second_diff = diff(f_diff, x)

    p = periodicity(f, x)
    if(p == 0 or p == None):
        domain = continuous_domain(f, x, S.Reals)
        domainDiff = continuous_domain(f_second_diff, x, S.Reals)
        finalUnion = domain.intersect(domainDiff)
        stPoints = stationary_points(f_diff, x, S.Reals)

    else:
        domain = continuous_domain(f, x, Interval(0, p))
        domainDiff = continuous_domain(f_second_diff, x, Interval(0, p))
        finalUnion = domain.intersect(domainDiff)
        stPoints = stationary_points(f_diff, x, Interval(0, p))

    unionInc = Union()
    unionDec = Union()
    condition = False

    unionOfConditionSet = False
    if(isinstance(stPoints, Union)):
        for element in stPoints.args:
            if(isinstance(element, ConditionSet)):
                unionOfConditionSet = True
                break

    if(isinstance(stPoints,ConditionSet) or unionOfConditionSet):
        stPoints = solve(f_second_diff, x)
        if(len(stPoints)==0):
             condition = True
    else:
        if(stPoints.is_empty):
            condition = True
    if condition:
        if isinstance(finalUnion, Interval):
            if is_convex(f, x, domain = finalUnion):
                unionInc = Union(unionInc, finalUnion)
            else:
                unionDec = Union(unionDec, finalUnion)
        else:
            for interval in finalUnion.args:
                if is_convex(f, x, domain = interval):
                    unionInc = Union(unionInc, interval)
                else:
                    unionDec = Union(unionDec, interval)


    else:
        finalUnion = IntervalParsing(finalUnion, stPoints)
        
        for interval in finalUnion.args:
            if is_convex(f, x, domain = interval):
                unionInc = Union(unionInc, interval)
            else:
                unionDec = Union(unionDec, interval)

    return ( DomainToString(unionInc), DomainToString(unionDec)  )
      

def CheckMonotonicity(fun):
    x = Symbol('x', real = True)
    f = eval(fun)
    f_diff = diff(f, x)

    p = periodicity(f, x)
    if(p == 0 or p == None):
        domain = continuous_domain(f, x, S.Reals)
        domainDiff = continuous_domain(f_diff, x, S.Reals)
        finalUnion = domain.intersect(domainDiff)
        stPoints = stationary_points(f, x, S.Reals)

    else:
        domain = continuous_domain(f, x, Interval(0, p))
        domainDiff = continuous_domain(f_diff, x, Interval(0, p))
        finalUnion = domain.intersect(domainDiff)
        stPoints = stationary_points(f, x, Interval(0, p))

    unionInc = Union()
    unionDec = Union()
    condition = False

    unionOfConditionSet = False
    if(isinstance(stPoints, Union)):
        for element in stPoints.args:
            if(isinstance(element, ConditionSet)):
                unionOfConditionSet = True
                break
    
    if(isinstance(stPoints,ConditionSet) or unionOfConditionSet):
        stPoints = solve(f_diff, x)
        print(stPoints)
        if(len(stPoints)==0):
             condition = True
    else:
        if(stPoints.is_empty):
            condition = True
    if condition:
        if isinstance(finalUnion, Interval):
            if is_increasing(f, finalUnion, x):
                unionInc = Union(unionInc, finalUnion)
            else:
                unionDec = Union(unionDec, finalUnion)
        else:
            for interval in finalUnion.args:
                if is_increasing(f, interval, x):
                    unionInc = Union(unionInc, interval)
                else:
                    unionDec = Union(unionDec, interval)


    else:
        finalUnion = IntervalParsing(finalUnion, stPoints)
        
        for interval in finalUnion.args:
            if is_increasing(f, interval, x):
                unionInc = Union(unionInc, interval)
            else:
                unionDec = Union(unionDec, interval)

    return ( DomainToString(unionDec), DomainToString(unionInc) )


def IntervalParsing(interval, stPoints):
    finalUnion = interval
    for element in stPoints:
        if(isinstance(finalUnion, Interval)):
            if(finalUnion.contains(element)):
                int1 = Interval(finalUnion.left, element,left_open = finalUnion.left_open, right_open = True)
                int2 = Interval(element, finalUnion.right, left_open = True, right_open = finalUnion.right_open)
                finalUnion = Union(int1, int2)

        else:
            finalUnion = UnionParsing(finalUnion, element)
   
    return finalUnion


                


def UnionParsing(union, stPoint):
    finalUnion = Union()
    for interval in union.args:
            if interval.contains(stPoint):
                int1 = Interval(interval.left, stPoint,left_open = interval.left_open, right_open = True)
                int2 = Interval(stPoint, interval.right, left_open = True, right_open = interval.right_open)
                u = Union(int1, int2)
                finalUnion = Union(finalUnion,u)
            else:
                finalUnion = Union(finalUnion,interval)
    return finalUnion
    


#print(GetConvexity("(1 + ln(abs(x)))/(x*(1 - ln(abs(x))))"))
# print(GetConvexity("(e**x-e**(-x))/(e**x+e**(-x))"))
#print(CheckMonotonicity("(x-2)/((log(x-2))**2)"))








    




