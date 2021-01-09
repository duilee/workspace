######################
# Required Questions #
######################

def coords(fn, seq, lower, upper):
    """
    >>> seq = [-4, -2, 0, 1, 3]
    >>> def fn(x):
    ...     return x**2
    >>> coords(fn, seq, 1, 9)
    [[-2, 4], [1, 1], [3, 9]]
    """
    return [[x,fn(x)] for x in seq if fn(x) >= lower and fn(x) <= upper]



def repeated(f, n):
    """Return the function that computes the nth application of f.
    >>> def square(x):
    ...     return x * x
    >>> def triple(x):
    ...     return 3 * x
    >>> def identity(x):
    ...     return x
    >>> def increment(x):
    ...     return x + 1
    >>> add_three = repeated(increment, 3)
    >>> add_three(5)
    8
    >>> repeated(triple, 5)(1) # 3 * 3 * 3 * 3 * 3 * 1
    243
    >>> repeated(square, 2)(5) # square(square(5))
    625
    >>> repeated(square, 4)(5) # square(square(square(square(5))))
    152587890625
    """
    """Return a value with nth repetition of f on x"""
    def g(x):
        time = 0 
        value = x
        while time < n:
            value = f(value)
            time += 1
        return value

    return g

def compose1(f, g):
    """Return a function h, such that h(x) = f(g(x))."""
    def h(x):
        return f(g(x))
    return h

def double(f):
    """ Return a function that applies f twice.
    >>> def square(x):
    ...     return x * x

    f -- a function that takes one argument

    >>> double(square)(2)
    16
    """
    return repeated(f, 2)


def count_cond(condition, n):
    """
    >>> def divisible(n, i):
    ...     return n % i == 0
    >>> count_cond(divisible, 2) # 1, 2
    2
    >>> count_cond(divisible, 4) # 1, 2, 4
    3
    >>> count_cond(divisible, 12) # 1, 2, 3, 4, 6, 12
    6

    >>> def is_prime(n, i):
    ...     return count_cond(divisible, i) == 2
    >>> count_cond(is_prime, 2) # 2
    1
    >>> count_cond(is_prime, 3) # 2, 3
    2
    >>> count_cond(is_prime, 4) # 2, 3
    2
    >>> count_cond(is_prime, 5) # 2, 3, 5
    3
    >>> count_cond(is_prime, 20) # 2, 3, 5, 7, 11, 13, 17, 19
    8
    """
    i, count = 1, 0
    while i <= n:
        if condition(n,i) == True:
            count += 1
        i += 1

    return count


def match_and_apply(pairs, function):
    """
    >>> pairs = [[1, 2], [3, 4], [5, 6], [7, 8], [9, 0]]
    >>> def square(num):
    ...     return num**2
    >>> func = match_and_apply(pairs, square)
    >>> result = func(3)
    >>> result
    16
    >>> result = func(1)
    >>> result
    4
    >>> result = func(7)
    >>> result
    64
    >>> result = func(15)
    >>> print(result)
    None

    """
    def f(n):
        for (x,y) in pairs:
            if x == n:
                return function(y) 
        return "None"

    return f
