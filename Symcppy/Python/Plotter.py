from sympy import *
from sympy.calculus.util import continuous_domain
from sympy.plotting import plot
import numbers
import math

def convertExpressionList(expressionList):
	numberList = []
	for expression in expressionList:
		numberList.append(expression.evalf())
	return numberList


def getDomain(function):
    x = Symbol('x', real = True)
    f= eval(function)
    return continuous_domain(f, x, S.Reals)


def findDiscontinuities(function):
    domain = getDomain(function)
    return (list)(domain.boundary)


def findVerticalAsymptotes(function):
    x = symbols('x', real = True)
    f = eval(function)
    vAsymptote = []
    bound = []
    bound = findDiscontinuities(function)
    lim = []
    if not bound:
        return vAsymptote
    else:
        for i in range(0, len(bound)):
            l1 = limit(f, x, bound[i], '-')
            l2 = limit(f, x, bound[i], '+')
            if math.isinf(re(l1)) or math.isinf(re(l2)):
                vAsymptote.append( bound[i])

    
    return vAsymptote


def findHorizontalAsymptotes(function):
    x = symbols('x', real = True)
    fun = eval(function)
    hAsy = []
    h1 = limit(fun ,x, '+oo')
    h2 = limit(fun, x, '-oo')
    if  isinstance(h1,numbers.Number) and not math.isinf(h1):
        hAsy.append(h1)
    if  isinstance(h2,numbers.Number) and not math.isinf(h2):
        hAsy.append(h2)
    
    return hAsy


def findObliqueAsymptote(function):
    x = symbols('x', real = True)
    f = eval(function)
    oAsymptotes = []
    k1 = limit(f/x, x, '+oo')
    k2 = limit(f/x, x, '-oo')

    if isinstance(k1, numbers.Number) and k1 != 0 and not math.isinf(k1):
        n1 = limit(f-k1*x, x, '+oo')
        if not math.isinf(n1):
            asymptote1 = k1*x + n1
            oAsymptotes.append(asymptote1)
    if isinstance(k2, numbers.Number) and k2 != 0 and not math.isinf(k2):
        n2 = limit(f - k2*x, x, '-oo')
        if not math.isinf(n2):
            asymptote2 = k2*x + n2
            oAsymptotes.append(asymptote2)

    oAsymptotes = list(dict.fromkeys(oAsymptotes))
    return oAsymptotes
        
    
    
def Plot(function):
    x = symbols('x', real = True)
    y = symbols('y')
    fun = eval(function)
    hAsymptote = findHorizontalAsymptotes(function)
    print(hAsymptote)
    vAsymptote = findVerticalAsymptotes(function)
    print(vAsymptote)
    oAsymptote = findObliqueAsymptote(function)
    print(oAsymptote)
    vAsymptote.sort()
    if not vAsymptote:
       p= plot(fun, show =  False, title = "f(x) = " + function)
       for i in hAsymptote:
           ha = plot(i, show = False, line_color = 'red')
           p.extend(ha)
        
       for j in oAsymptote:
           oa = plot(j, show = False, line_color = 'red')
           p.extend(oa)
        
       p.show()


    else:
        prevVert = vAsymptote[0]
        f1 = Piecewise((fun, x < vAsymptote[0]))
        p = plot(f1, show = False, ylim=[-5,5], title = 'f(x) = ' + function)

        for i in range(1, len(vAsymptote)):
            pTemp = plot(fun, (x, prevVert, vAsymptote[i]), show = False)
            p.extend(pTemp)
            prevVert = vAsymptote[i]

        f2 = Piecewise((fun, x>vAsymptote[len(vAsymptote)-1]))
        pTemp = plot(f2, show = False)
        p.extend(pTemp)

        for i in vAsymptote:
            va = plot_implicit(Eq(x,i), show = False, line_color = 'red')
            p.extend(va)

        for i in hAsymptote:
            ha = plot(i, show = False, line_color = 'red')
            p.extend(ha) 
        for i in oAsymptote:
            oa = plot(i, show = False, line_color = 'red')
            p.extend(oa)   
        p.show()
