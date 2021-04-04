# Complete the arrayManipulation function below.
# https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays&h_r=next-challenge&h_v=zen

# very smart algorithm
def arrayManipulation(n, queries):
    arr = [0] * (n + 1)

    for query in queries:
        arr[query[0] - 1] += query[2]
        arr[query[1]] -= query[2]

    max_value = 0
    arr_sum = 0

    for i in range(n):
        arr_sum += arr[i]
        if arr_sum >= max_value:
            max_value = arr_sum

    return max_value
