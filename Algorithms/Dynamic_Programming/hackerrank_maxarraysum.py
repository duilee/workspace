# Complete the maxSubsetSum function below.
# https://www.hackerrank.com/challenges/max-array-sum/problem
def maxSubsetSum(arr):
    maxsum_lst = [0] * len(arr)
    maxsum_lst[0] = arr[0]
    maxsum_lst[1] = max(arr[0], arr[1])

    for i, num in enumerate(arr[2:], start=2):
        maxsum_lst[i] = max(num, maxsum_lst[i - 1], maxsum_lst[i - 2] + num)

    return maxsum_lst[-1]