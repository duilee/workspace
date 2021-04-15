from collections import Counter

# USE TWO COUNTERS
# Complete the isValid function below.
# https://www.hackerrank.com/challenges/sherlock-and-valid-string
def isValid(s):
    counts_dict = Counter(s)
    freq_dict = Counter(counts_dict.values())

    if len(freq_dict) == 1:
        return "YES"
    elif len(freq_dict) == 2:
        min_freq = min(freq_dict.keys())
        max_freq = max(freq_dict.keys())

        if max_freq - min_freq == 1 and freq_dict[max_freq] == 1:
            return "YES"
        elif min_freq == 1 and freq_dict[min_freq] == 1:
            return "YES"
        else:
            return "NO"
    else:
        return "NO"