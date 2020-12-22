from sympy import *
from sympy.calculus.util import continuous_domain

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


def ValueAt(function, coord):
    x = symbols('x')
    expr = eval(function)
<<<<<<< Updated upstream
    domain = continuous_domain(expr, x, S.Reals)
    if domain.contains(coord):
        return float(expr.subs(x, coord))
    else:
        return 'None'



=======
    return float(expr.subs(x, coord))
>>>>>>> Stashed changes
