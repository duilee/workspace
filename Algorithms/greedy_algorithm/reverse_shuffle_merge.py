from collections import Counter

# https://www.hackerrank.com/challenges/reverse-shuffle-merge
# Complete the reverseShuffleMerge function below.
def reverseShuffleMerge(s):
    s = list(reversed(s))
    remain_dict = Counter(s)

    required_dict = {}
    added_dict = {}
    for i in remain_dict:
        required_dict[i] = remain_dict[i] // 2
        added_dict[i] = 0

    char_lst = []
    min_char = "|"
    min_index = 0
    index = 0

    while index < len(s):
        char = s[index]
        if required_dict[char] > added_dict[char]:
            if char < min_char:
                min_char = char
                min_index = index
            if remain_dict[char] - 1 < required_dict[char] - added_dict[char]:
                while index > min_index:
                    index -= 1
                    char = s[index]
                    remain_dict[char] += 1
                added_dict[char] += 1
                char_lst.append(char)
                min_char = '|'
        remain_dict[char] -= 1
        index += 1

    return ''.join(char_lst)