# Complete the getMinimumCost function below.
# https://www.hackerrank.com/challenges/greedy-florist
def getMinimumCost(k, c):
    c.sort(reverse=True)
    total_sum = 0

    for i in range(len(c)):
        total_sum += c[i] * ((i // k) + 1)

    return total_sum