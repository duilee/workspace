# Complete the alternatingCharacters function below.
# https://www.hackerrank.com/challenges/alternating-characters
def alternatingCharacters(s):
    prev_char = s[0]
    count = 0

    for i in s[1:]:
        if i != prev_char:
            prev_char = i
        else:
            count += 1

    return count