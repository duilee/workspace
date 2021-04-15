"""
from collections import Counter
def number_needed(a, b):
    ct_a = Counter(a)
    ct_b = Counter(b)
    ct_a.subtract(ct_b)
    return sum(abs(i) for i in ct_a.values())
"""


# Complete the makeAnagram function below.
def makeAnagram(a, b):
    b_dict = Counter(b)
    ang_len = 0

    for i in a:
        if i in b_dict:
            if b_dict[i] > 0:
                ang_len += 1
                b_dict[i] -= 1

    count = len(a) - ang_len + (len(b) - ang_len)

    return count