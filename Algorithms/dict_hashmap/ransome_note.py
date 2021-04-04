# Complete the checkMagazine function below.
# https://www.hackerrank.com/challenges/ctci-ransom-note/problem
def checkMagazine(magazine, note):
    word_dict = {}

    for a_word in magazine:
        if a_word in word_dict:
            word_dict[a_word] = word_dict[a_word] + 1
        else:
            word_dict[a_word] = 1

    for a_word in note:
        if a_word in word_dict:
            if word_dict[a_word] == 0:
                print("No")
                return
            else:
                word_dict[a_word] = word_dict[a_word] - 1
        else:
            print("No")
            return