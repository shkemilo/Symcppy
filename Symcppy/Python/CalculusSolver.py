from sympy import *
from sympy.calculus.util import continuous_domain, stationary_points, function_range, is_convex

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
    x = Symbol('x', real = True)
    f = eval(function)
    m = minimum(f, x, S.Reals)
    
    if isinstance(m, numbers.Number) and not math.isinf(m):
        return float(m)
    else:
        return 'None'

def GetMax(function):
    x = Symbol('x', real = True)
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
        return "Aperiodic"
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
    

  


#def CheckMonotonicity(fun):
   # x = symbols('x', real = True)
    #f = eval(fun)
    #domain = continuous_domain(f, x, S.Reals)
    #union_increasing = Union()
    #union_decreasing = Union()
    #if isinstance(domain, Interval):
      #  if is_increasing(f, domain, x):
       #     union_increasing = Union(union_increasing, domain)
       # else:
      #      union_decreasing = Union(union_decreasing, domain)
   # else:
      #  for i in domain.args:
       #     if is_increasing(f, i, x):
         #       union_increasing = Union(union_increasing, i)
         #   else:
         #       union_decreasing = Union(union_decreasing, i)

<<<<<<< Updated upstream
    #return (DomainToString(union_increasing), DomainToString(union_decreasing))
=======
def convertExpressionList(expressionList):
	numberList = []
	for expression in expressionList:
		numberList.append(float(re(expression)))
	return numberList

def GetZeros(function):
    x = symbols('x', real = True)
    print(function)
    f = eval(function)
    exList = solve(f, x)
    return convertExpressionList(exList) 
>>>>>>> Stashed changes

def CheckMonotonicity(fun):
    x = symbols('x', real = True)
    f = eval(fun)
    f_diff = diff(f, x)

    domain = continuous_domain(f, x, S.Reals)
    domainDiff = continuous_domain(f_diff, x, S.Reals)
    finalUnion = domain.intersect(domainDiff)
    unionInc = Union()
    unionDec = Union()
<<<<<<< Updated upstream
    stPoints = stationary_points(f, x, S.Reals)
    

    if stPoints.is_empty:
=======
    #stPoints = stationary_points(f, x, S.Reals)
    stPoints = GetZeros(str(f_diff))
    
    if stPoints == []:
>>>>>>> Stashed changes
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
        if isinstance(finalUnion, Interval):
            for element in stPoints:
                if finalUnion.contains(element):
                    int1 = Interval(finalUnion.left, element,left_open = finalUnion.left_open, right_open = True)
                    int2 = Interval(element, finalUnion.right, left_open = True, right_open = finalUnion.right_open)
                    u = Union(int1, int2)
                    finalUnion = finalUnion.intersect(u)
        else:


            for interval in finalUnion.args:
                for element in stPoints:
                    if interval.contains(element):
                        int1 = Interval(interval.left, element,left_open = interval.left_open, right_open = True)
                        int2 = Interval(element, interval.right, left_open = True, right_open = interval.right_open)
                        u = Union(int1, int2)
                        finalUnion = finalUnion.intersect(u)
        
        for interval in finalUnion.args:
            if is_increasing(f, interval, x):
                unionInc = Union(unionInc, interval)
            else:
                unionDec = Union(unionDec, interval)
<<<<<<< Updated upstream

    return (DomainToString(unionInc), DomainToString(unionDec))

def CheckIfConvex(fun):
    x = symbols('x', real = True)
    f = eval(fun)
    f_diff = diff(f, x)
    f_dDiff = diff(f_diff, x)

    domain = continuous_domain(f, x, S.Reals)
    domainDiff = continuous_domain(f_dDiff, x, S.Reals)
    finalUnion = domain.intersect(domainDiff)
    unionInc = Union()
    unionDec = Union()
    stPoints = stationary_points(f, x, S.Reals)
    

    if stPoints.is_empty:
        if isinstance(finalUnion, Interval):
            if is_convex(f, finalUnion, x):
                unionInc = Union(unionInc, finalUnion)
            else:
                unionDec = Union(unionDec, finalUnion)
        else:
            for interval in finalUnion.args:
                if is_convex(f, interval, x):
                    unionInc = Union(unionInc, interval)
                else:
                    unionDec = Union(unionDec, interval)


    else:
        if isinstance(finalUnion, Interval):
            for element in stPoints:
                if finalUnion.contains(element):
                    int1 = Interval(finalUnion.left, element,left_open = finalUnion.left_open, right_open = True)
                    int2 = Interval(element, finalUnion.right, left_open = True, right_open = finalUnion.right_open)
                    u = Union(int1, int2)
                    finalUnion = finalUnion.intersect(u)
        else:


            for interval in finalUnion.args:
                for element in stPoints:
                    if interval.contains(element):
                        int1 = Interval(interval.left, element,left_open = interval.left_open, right_open = True)
                        int2 = Interval(element, interval.right, left_open = True, right_open = interval.right_open)
                        u = Union(int1, int2)
                        finalUnion = finalUnion.intersect(u)
        
        for interval in finalUnion.args:
            if is_convex(f, interval, x):
                unionInc = Union(unionInc, interval)
            else:
                unionDec = Union(unionDec, interval)

    return (DomainToString(unionInc), DomainToString(unionDec))



            




    





    
=======

    return (DomainToString(unionDec), DomainToString(unionInc))
>>>>>>> Stashed changes

def GetConvexity(fun):
    x = symbols('x', real = True)
    f = sympify(fun)
    f_diff = diff(f, x)
    f_dDiff = diff(f_diff, x)

    domain = continuous_domain(f, x, S.Reals)
    domainDiff = continuous_domain(f_dDiff, x, S.Reals)
    finalUnion = domain.intersect(domainDiff)
    unionInc = Union()
    unionDec = Union()
    #stPoints = stationary_points(f, x, S.Reals)
    stPoints = GetZeros(str(f_diff))
    
    if stPoints == []:
        if isinstance(finalUnion, Interval):
            if is_convex(f, x, domain = finalUnion):
                unionInc = Union(unionInc, finalUnion)
            else:
                unionDec = Union(unionDec, finalUnion)
        else:
            for interval in finalUnion.args:
                if is_convex(f, interval, x):
                    unionInc = Union(unionInc, interval)
                else:
                    unionDec = Union(unionDec, interval)


    else:
        if isinstance(finalUnion, Interval):
            for element in stPoints:
                if finalUnion.contains(element):
                    int1 = Interval(finalUnion.left, element,left_open = finalUnion.left_open, right_open = True)
                    int2 = Interval(element, finalUnion.right, left_open = True, right_open = finalUnion.right_open)
                    u = Union(int1, int2)
                    finalUnion = finalUnion.intersect(u)
        else:


            for interval in finalUnion.args:
                for element in stPoints:
                    if interval.contains(element):
                        int1 = Interval(interval.left, element,left_open = interval.left_open, right_open = True)
                        int2 = Interval(element, interval.right, left_open = True, right_open = interval.right_open)
                        u = Union(int1, int2)
                        finalUnion = finalUnion.intersect(u)
        
        for interval in finalUnion.args:
            if is_convex(f, x, domain = interval):
                unionInc = Union(unionInc, interval)
            else:
                unionDec = Union(unionDec, interval)

    return (DomainToString(unionDec), DomainToString(unionInc))
