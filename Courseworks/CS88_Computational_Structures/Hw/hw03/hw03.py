######################
# Required Questions #
######################

def falling(n, k):
    """Compute the falling factorial of n to depth k.

    >>> falling(6, 3)  # 6 * 5 * 4
    120
    >>> falling(4, 0)
    1
    >>> falling(4, 3)  # 4 * 3 * 2
    24
    >>> falling(4, 1)  # 4
    4
    >>> falling(4, 10)  # 4 * 3 * 2 * 1 # Only n times!!
    24
    """
    total = 1

    while k > 0 and n > 0:
        total = total * n
        n = n - 1
        k = k - 1
    return total 



def nonzero(lst):
    """ Returns the first nonzero element of a list

    >>> nonzero([1, 2, 3])
    1
    >>> nonzero([0, 1, 2])
    1
    >>> nonzero([0, 0, 0, 0, 0, 0, 5, 0, 6])
    5
    """
    index = 0
    while lst[index] == 0 :
        index += 1
    return lst[index]


def hailstone(n):
    """Print the hailstone sequence starting at n and return its
    length.

    >>> a = hailstone(10)
    10
    5
    16
    8
    4
    2
    1
    >>> a
    7
    """
    step = 1
    print(n) 
    while n != 1:
        if n % 2 == 0:
            n = n / 2
            step += 1
            print(int(n))
        else:
            n = n * 3 + 1
            step += 1
            print(int(n))
    return step


def odd_even(x):
    """
    Classify a number as odd or even.
    >>> odd_even(4)
    'even'
    >>> odd_even(3)
    'odd'
    """
    if x % 2 == 0:
        return 'even'
    else:
        return 'odd'

def classify(s):
    """
    Classify all the elements of a sequence as odd or even
    >>> classify([0, 1, 2, 4])
    ['even', 'odd', 'even', 'even'] 
    """
    lst = []
    for x in s:
        lst += [odd_even(x)]
    return lst


def decode_helper(pair):
    """
    Optional helper function! Could be useful to turn something like [0, 0] to 'Male 0-9'
    """
    if pair[0] == 0:
        sex = 'Male'
    else:
        sex = 'Female'

    if pair[1] == 10:
        return sex + " " + '100+'
    else:
        age = pair[1]*10
        return sex + " " + str(age) + '-' + str(age + 9)
    

def decode(list_of_sex_age_pairs):
    """
    >>> decode([[0, 0], [1, 1], [1, 10]])
    ['Male 0-9', 'Female 10-19', 'Female 100+']
    >>> decode([[0, 0], [0, 1], [0, 2], [0, 3], [0, 4], [1, 5], [1, 6], [1, 7], [1, 8], [1, 9], [1, 10]])
    ['Male 0-9', 'Male 10-19', 'Male 20-29', 'Male 30-39', 'Male 40-49', 'Female 50-59', 'Female 60-69', 'Female 70-79', 'Female 80-89', 'Female 90-99', 'Female 100+']    
    """ 
    lst = []
    for x in list_of_sex_age_pairs:
        lst += [decode_helper(x)]
    return lst

