#############
# Iterators #
#############

# Q2
class IteratorRestart:
    """
    >>> iterator = IteratorRestart(2, 7)
    >>> for num in iterator:
    ...     print(num)
    2
    3
    4
    5
    6
    7
    >>> for num in iterator:
    ...     print(num)
    2
    3
    4
    5
    6
    7
    """
    def __init__(self, start, end):
        self.start = start - 1
        self.begin = start - 1
        self.end = end

    def __next__(self):
        if self.start == self.end:
        	self.start = self.begin
        	raise StopIteration
        self.start += 1
        return self.start


    def __iter__(self):
        return self


# Q3
class Str:
    """
    >>> s = Str("hello")
    >>> for char in s:
    ...     print(char)
    ...
    h
    e
    l
    l
    o
    >>> for char in s:    # a standard iterator does not restart
    ...     print(char)
    """
    def __init__(self, string):
    	self.start = -1
    	self.string = string

    def __next__(self):
    	if self.start == (len(self.string)-1):
    		raise StopIteration
    	self.start += 1
    	return self.string[self.start]

    def __iter__(self):
    	return self



##############
# Generators #
##############

# Q4
def countdown(n):
    """
    >>> from types import GeneratorType
    >>> type(countdown(0)) is GeneratorType # countdown is a generator
    True
    >>> for number in countdown(5):
    ...     print(number)
    ...
    5
    4
    3
    2
    1
    0
    """
    i = n
    while i >= 0:
    	yield i
    	i -= 1

class Countdown:
    """
    >>> from types import GeneratorType
    >>> type(Countdown(0)) is GeneratorType # Countdown is an iterator
    False
    >>> for number in Countdown(5):
    ...     print(number)
    ...
    5
    4
    3
    2
    1
    0
    """
    def __init__(self, number):
    	self.number = number

    def __iter__(self):
    	while self.number >= 0:
    		yield self.number
    		self.number -= 1

# Q5
def hailstone(n):
    """
    >>> for num in hailstone(10):
    ...     print(num)
    ...
    10
    5
    16
    8
    4
    2
    1
    """
    i = n
    while i != 1:
    	if i % 2 == 0:
    		yield int(i)
    		i = i / 2
    	else:
    		yield int(i)
    		i = (i*3)+1
    	if i == 1:
    		yield int(i)

