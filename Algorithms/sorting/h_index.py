# https://programmers.co.kr/learn/courses/30/lessons/42747
def solution(citations):
    max_h = 0
    max_v = max(citations)

    for i in range(max_v + 1):
        h_smaller = sum([i >= j for j in citations])
        h_greater = sum([i <= j for j in citations])

        if h_greater >= i and h_smaller <= i:
            if i > max_h:
                max_h = i

    return max_h