# Complete the pairs function below.
# https://www.hackerrank.com/challenges/pairs
# for difference use add... think differently
def pairs(k, arr):
    """
    arr.sort()

    count = 0
    for i in range(len(arr)-1):
        for j in range(1, len(arr)):
            if arr[j] - arr[i] > k:
                break
            if arr[j] - arr[i] == k:
                count += 1

    return count
    """

    counts_dict = Counter(arr)
    count = 0

    for i in counts_dict:
        if counts_dict[i + k] >= 1:
            count += 1

    return count