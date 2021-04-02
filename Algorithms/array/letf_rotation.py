# Complete the rotLeft function below.
# https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays&h_r=next-challenge&h_v=zen
def rotLeft(a, d):
    for _ in range(d):
        first_element = a.pop(0)
        a.append(first_element)

    return a
