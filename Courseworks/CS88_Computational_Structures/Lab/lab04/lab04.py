# Question 1

def data_clean(a):
    """Write a function that rounds each element of the list down to the nearest tens place.


    >>> a = [12, 23, 34]
    >>> data_clean(a)
    [10, 20, 30]
    >>> b = [238, 193, 928]
    >>> data_clean(b)
    [230, 190, 920]
    >>> c = [10, 20, 30]
    >>> data_clean(c)
    [10, 20, 30]
    >>> d = [9, 9, 9]
    >>> data_clean(d)
    [0, 0, 0]
    """
    def tenth(x):
        return (x // 10) * 10
    
    return list(map(tenth, a))


# Question 2

from operator import add, mul

def reduce(reducer, s, base):
    """Reduce a sequence under a two-argument function starting from a base value.

    >>> def add(x, y):
    ...     return x + y
    >>> def mul(x, y):
    ...     return x*y
    >>> reduce(add, [1,2,3,4], 0)
    10
    >>> reduce(mul, [1,2,3,4], 0)
    0
    >>> reduce(mul, [1,2,3,4], 1)
    24
    """

    total = base

    for x in s:
        total = reducer(total, x)

    return total


# Question 3

def piecewise(f, g, b):
    """Returns the piecewise function h where:

    h(x) = f(x) if x < b,
           g(x) otherwise

    >>> def negate(x):
    ...     return -x
    >>> def identity(x):
    ...     return x
    >>> abs_value = piecewise(negate, identity, 0)
    >>> abs_value(6)
    6
    >>> abs_value(-1)
    1
    """
    def h(x):
        if x < b:
            return f(x)
        else:
            return g(x)
    return h


# Question 4

def make_buzzer(n):
    """ Returns a function that prints numbers in a specified
    range except those divisible by n.

    >>> i_hate_fives = make_buzzer(5)
    >>> i_hate_fives(10)
    Buzz!
    1
    2
    3
    4
    Buzz!
    6
    7
    8
    9
    """
    def f(x):
        for i in range(x):
            if i % n == 0:
                print("Buzz!")
            else:
                print(i)
    return f


# Question 5

def intersects(f, x):
    """Returns a function that returns whether f intersects g at x.

    >>> def square(x):
    ...     return x * x
    >>> def triple(x):
    ...     return x * 3
    >>> def increment(x):
    ...     return x + 1
    >>> def identity(x):
    ...     return x
    >>> at_three = intersects(square, 3)
    >>> at_three(triple) # triple(3) == square(3)
    True
    >>> at_three(increment)
    False
    >>> at_one = intersects(identity, 1)
    >>> at_one(square)
    True
    >>> at_one(triple)
    False
    """
    def h(g):
        return g(x) == f(x)
    return h

