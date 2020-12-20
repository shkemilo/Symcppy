from sympy import *
from sympy.calculus.util import continuous_domain

def convertExpressionList(expressionList):
	numberList = []
	for expression in expressionList:
		numberList.append(expression.evalf())
	return numberList


def GetZeros(function, funVariable):
    x = symbols('x', real = True)
    f = eval(function)
    exList = solve(f, x)
    return convertExpressionList(exList) 


def ValueAt(function, coord):
    x = symbols('x')
    expr = eval(function)
    domain = continuous_domain(expr, x, S.Reals)
    if domain.contains(coord):
        return float(expr.subs(x, coord))
    else:
        return 'None'



