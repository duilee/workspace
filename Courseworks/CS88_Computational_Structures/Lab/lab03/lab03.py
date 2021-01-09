# Question 1-2


def tax(shopping_cart, percent):
    """
    Adds a `percent` tax to each item's price in a shopping cart.

    >>> fruitCart = [("apple", 0.5, 3), ("banana", 0.25, 4)]
    >>> tax(fruitCart, 10)
    [('apple', 0.55, 3), ('banana', 0.275, 4)]

    >>> calCart = [("oski", 1000, 1), ("go", 1, 2), ("bears", 3.5, 2)]
    >>> tax(calCart, 100)
    [('oski', 2000.0, 1), ('go', 2.0, 2), ('bears', 7.0, 2)]
    """
    return [(x,y*(1+percent/100),z) for x,y,z, in shopping_cart]

def cartSum(shopping_cart):
    """
    Sums a shopping cart

    >>> fruitCart = [("apple", 0.5, 3), ("banana", 0.25, 4)]
    >>> taxedFruit = tax(fruitCart, 10)
    >>> cartSum(taxedFruit)
    2.75
    >>> calCart = [("oski", 1000, 1), ("go", 1, 2), ("bears", 3.5, 2)]
    >>> taxedCal = tax(calCart, 100)
    >>> cartSum(taxedCal)
    2018.0
    """
    return sum([y*z for x,y,z in shopping_cart])


# Question 3

def where_above(list, limit):
    """
    where_above behaves like table.where(column, are.above(limit)).
    The analogy is completed if you think of a column of a table as a list and return the filtered column instead of the entire table.

    >>> where_above([1, 2, 3], 2)
    [3]
    >>> where_above(range(13), 10)
    [11, 12]
    >>> where_above(range(123), 120)
    [121, 122]

    """
    "*** YOUR CODE HERE ***"
    return [x for x in list if x > limit]


# Question 4

def minmax(s):
    """Return the minimum and maximum elements of a sequence.

    >>> minmax([1, 2, -3])
    (-3, 2)
    >>> minmax([2])
    (2, 2)
    >>> minmax([])
    (None, None)
    """
    if s == []: 
        return (None, None)

    min = s[0]
    max = s[0]

    for number in s:
        if number > max:
            max = number
        if number < min:
            min = number
    return (min, max)


# Question 5

def closest_power_2(x):
    """ Returns the closest power of 2 that is less than x
    >>> closest_power_2(6)
    4
    >>> closest_power_2(32)
    16
    >>> closest_power_2(87)
    64
    >>> closest_power_2(4095)
    2048
    >>> closest_power_2(524290)
    524288
    """
    y = 1
    while 2**y < x:
        y += 1
    return 2**(y-1)

