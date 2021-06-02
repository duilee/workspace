# https://programmers.co.kr/learn/courses/30/lessons/42842
import math


def solution(brown, yellow):
    k = int(math.sqrt(yellow)) + 1

    for i in range(1, k + 1):
        if yellow % i == 0:
            prod = ((yellow / i) + 2) * (i + 2)
            if prod - yellow == brown:
                answer = [yellow / i + 2, i + 2]
                return answer

    answer = []
    return answer