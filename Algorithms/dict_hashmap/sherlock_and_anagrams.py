# Complete the sherlockAndAnagrams function below.
# https://www.hackerrank.com/challenges/sherlock-and-anagrams
def sherlockAndAnagrams(s):
    dict_ana = {}

    for i in range(1, len(s)):
        j = 0
        while (j + i) <= len(s):
            substr = s[j:j + i]
            substr_lst = [a_char for a_char in substr]
            substr_lst.sort()
            substr = ''.join(substr_lst)

            if substr in dict_ana:
                dict_ana[substr] = dict_ana[substr] + 1
            else:
                dict_ana[substr] = 1
            j += 1

    count = 0

    for i in dict_ana:
        count += (dict_ana[i] * (dict_ana[i] - 1)) // 2

    return count