# https://programmers.co.kr/learn/courses/30/lessons/42746
def solution(numbers):
    numbers = list(map(str, numbers))
    # use key to sort the numbers in string
    numbers.sort(key= lambda x: x*3, reverse=True)
    # convert to 0 for the cases when 0 is in front of the string
    return str(int(''.join(numbers)))