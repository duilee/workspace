# https://programmers.co.kr/learn/courses/30/lessons/42839
import math
from itertools import permutations

# check if a number is prime
# if num is less than 2, == 1 then False
def check_prime(num):
    k = math.sqrt(num)

    if num < 2:
        return False

    # check from 2 to sqrt(k)
    for i in range(2, int(k) + 1):
        if num % i == 0:
            return False

    return True


def solution(numbers):
    answer = []

    # get all the permutations and check if it is prime
    for i in range(1, len(numbers) + 1):
        num_lst = list(map(''.join, permutations(list(numbers), i)))
        for j in set(num_lst):
            if check_prime(int(j)):
                answer.append(int(j))

    return len(set(answer))