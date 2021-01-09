######################
# Required Questions #
######################


def temperature_converter(f_temp):
    """
    >>> celsius_temp1 = temperature_converter(32)
    >>> celsius_temp1
    0.0
    """
    celsius_temp = (f_temp - 32) * 5 / 9
    return celsius_temp

def pythagorean_triple(a,b,c):
    """
    >>> pythagorean_triple(3,4,5)
    True
    >>> pythagorean_triple(3,4,6)
    False
    """
    return (a**2 + b**2) == c**2

    


