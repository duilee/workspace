# https://programmers.co.kr/learn/courses/30/lessons/42578
def solution(clothes):
    count_dict = {}

    for cloth, c_type in clothes:
        if c_type in count_dict:
            count_dict[c_type] += 1
        else:
            count_dict[c_type] = 2

    answer = 1

    for c_type in count_dict:
        answer *= count_dict[c_type]

    answer -= 1

    return answer