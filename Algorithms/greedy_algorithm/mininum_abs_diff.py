# Complete the minimumAbsoluteDifference function below.
# https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array
def minimumAbsoluteDifference(arr):
    min_value = 999999

    arr.sort()

    for i in range(1, len(arr)):
        if abs(arr[i] - arr[i - 1]) < min_value:
            min_value = abs(arr[i] - arr[i - 1])

    return min_value

"""
# Initially used two loops, much efficient with sort first
# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(arr):
    min_value = 999999
    
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if abs(arr[i]-arr[j]) < min_value:
                min_value = abs(arr[i]-arr[j])
    
                
    return min_value
"""