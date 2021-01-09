"""Lab 2: Functions """

## Coding

def a_or_c(grade):
    """
    We all know the saying "C's get degrees".
    We all would like to get an A, but sometimes
    a C will have to do. 

    Return whether the grade inputted
    would receive an A or C.

    >>> a_or_c(100)
    True
    >>> a_or_c(75)
    True
    >>> a_or_c(82)
    False
    >>> a_or_c(80)
    False
    >>> a_or_c(95)
    True
    >>> a_or_c(40)
    False
    """
    if grade >= 90 or (grade >= 70 and 80 > grade):
        return(True)
    else:
        return(False)



## Control

def min(x, y):
    """
    Return the minimum between x and y

    >>> min(1,2)
    1
    >>> min(3,1)
    1
    >>> min(2,3)
    2
    >>> min(0, 67777)
    0
    >>> min(-1, -5)
    -5
    >>> min(-7, -1)
    -7
    >>> min(0, 0)
    0
    """

    if x > y:
        return(y)
    else:
        return(x)


## Transformation

def abs_value_equal(x, y):
    """Return whether or not the absolute value of both numbers is the same.

    Please refrain from using libraries (abs)

    >>> abs_value_equal(-2, -2)
    True
    >>> abs_value_equal(-3, 3)
    True
    >>> abs_value_equal(1, 2)
    False
    >>> abs_value_equal(3, 3)
    True
    >>> abs_value_equal(-6, -6)
    True
    >>> abs_value_equal(-1, -5)
    False
    >>> abs_value_equal(5, -6)
    False
    """
    if x == y or ((-1 * x ) == y):
        return(True)
    else:
        return(False)

## Representation

def mirror(num1, num2):
    """
    Return if num1 is num2 backwards
    The inputs will always be < 100.

    >>> mirror(12, 21)
    True
    >>> mirror(54, 45)
    True
    >>> mirror(33, 33)
    True
    >>> mirror(42, 52)
    False
    >>> mirror(12, 22)
    False
    """
    # YOUR CODE HERE
    x = num1 // 10
    y = num1 % 10
    if num2 == (y * 10 + x):
        return(True)
    else:
        return(False)

