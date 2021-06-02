# https://programmers.co.kr/learn/courses/30/lessons/43165
# with recursion
def solution(numbers, target):
    n = len(numbers)
    count = 0

    def find_sum(index, sum_value):
        if index == n:
            if sum_value == target:
                nonlocal count
                count += 1
                return
        else:
            find_sum(index + 1, sum_value + numbers[index])
            find_sum(index + 1, sum_value - numbers[index])

    find_sum(0, 0)

    return count

"""
# using dfs
def solution(numbers, target):
    answer = 0
    queue = [[numbers[0], 0], [-1*numbers[0], 0]]
    n = len(numbers)
    while queue:
        temp, idx = queue.pop()
        idx += 1
        if idx < n:
            queue.append([temp+numbers[idx], idx])
            queue.append([temp-numbers[idx], idx])
        else:
            if temp == target:
                answer += 1
    return answer
"""
