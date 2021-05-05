# https://programmers.co.kr/learn/courses/30/lessons/42840
def solution(answers):
    a = [1, 2, 3, 4, 5]
    b = [2, 1, 2, 3, 2, 4, 2, 5]
    c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    a_cor, b_cor, c_cor = 0, 0, 0

    for index, answer in enumerate(answers):
        if answer == a[index % len(a)]:
            a_cor += 1
        if answer == b[index % len(b)]:
            b_cor += 1
        if answer == c[index % len(c)]:
            c_cor += 1

    max_v = max(a_cor, b_cor, c_cor)

    ans_lst = []

    for index, i in enumerate([a_cor, b_cor, c_cor], start=1):
        if max_v == i:
            ans_lst.append(index)

    return ans_lst