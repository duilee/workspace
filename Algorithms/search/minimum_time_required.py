# Complete the minTime function below.
# https://www.hackerrank.com/challenges/minimum-time-required/problem
def minTime(machines, goal):
    machines.sort()
    len_machines = len(machines)

    # earlist day one can reach goal if all machines = 1 (hense divide by length)
    # Low bound, based on if all machines were the min machines
    low = math.ceil(goal / len_machines) * machines[0]
    # high bound for if all machines were the max machines
    high = math.ceil(goal / len_machines) * machines[-1]

    while low < high:
        # guess on days required
        guess = (low + high) // 2

        # compute how many items each machine can make, and adjust days
        if sum([guess // m for m in machines]) >= goal:
            high = guess
        else:
            low = guess + 1

    return low