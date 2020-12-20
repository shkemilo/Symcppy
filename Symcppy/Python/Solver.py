from sympy import *

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
    return float(expr.subs(x, coord))
