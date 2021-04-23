# Complete the maxMin function below.
# https://www.hackerrank.com/challenges/angry-children
def maxMin(k, arr):
    arr.sort()
    min_value = math.inf

    for i in range(len(arr) - k + 1):
        tmp = arr[i + k - 1] - arr[i]
        if tmp < min_value:
            min_value = tmp

    return min_value