# https://programmers.co.kr/learn/courses/30/lessons/42576
def solution(participant, completion):
    name_dict = {}
    key_dict = {}
    total_sum = 0
    for i, name in enumerate(participant):
        if name in key_dict:
            total_sum += key_dict[name]
        else:
            name_dict[i] = name
            key_dict[name] = i
            total_sum += i

    for i, name in enumerate(completion):
        total_sum -= key_dict[name]

    return name_dict[total_sum]

"""
# can also use Counter
import collections

def solution(participant, completion):
    participant_counter = collections.Counter(participant)
    completion_counter = collections.Counter(completion)
    result = list((participant_counter - completion_counter).keys())[0]
    return result
"""