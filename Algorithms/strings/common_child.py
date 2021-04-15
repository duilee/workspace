# https://www.hackerrank.com/challenges/common-child
# Complete the commonChild function below.

"""
It is based on dynamic too, and the idea is that each subsequence cell holds
the length of the longest subsequence that ends in the char at the same cell position on s1.
So, for a given char c the necessary operations to find
the longest subsequence ending in c are, search in s1 the chars
equal to c and update subsequence with the longest subsequence found that ends in the char.
Doing this procedure for all the elements of s2, the result will be the max(subsequence).

"""

def commonChild(s1, s2):
    subsequences = [0 for _ in s1]
    for c in s2:
        max_length = 0
        for i in range(len(s1)):
            tmp = subsequences[i]
            if c == s1[i]:
                subsequences[i] = max_length + 1

            max_length = max(tmp, max_length)
        # print(subsequences)
    return max(subsequences)

commonChild("SHINCHAN", "NOHARAAA")