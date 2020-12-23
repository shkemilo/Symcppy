from sympy import *
from sympy.calculus.util import continuous_domain

def GetZeros(function):
    x = symbols('x', real = True)
    f = eval(function)
    exList = solve(f, x)
    numberList = []
    for element in exList:
        if im(element.evalf()) == 0:
            numberList.append(float(element))
    return numberList

def ValueAt(function, coord):
    x = symbols('x')
    expr = eval(function)
    domain = continuous_domain(expr, x, S.Reals)
    if domain.contains(coord):
        return float(expr.subs(x, coord))
    else:
        return 'None'
