#https://programmers.co.kr/learn/courses/30/lessons/42577
from collections import Counter

def solution(phone_book):
    answer = True

    # get the lengths of substring we need to check
    len_list = list(set([len(i) for i in phone_book]))
    len_list.sort()
    len_list = len_list[:-1]

    # Use Counter to keep track of phone numbers in the book
    count_dict = Counter(phone_book)

    for a_num in phone_book:
        i = 0
        while i < len(len_list) and len_list[i] <= len(a_num):
            if a_num[:len_list[i]] != a_num and count_dict[a_num[:len_list[i]]] > 0:
                return False
            i += 1

    return answer