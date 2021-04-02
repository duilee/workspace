# Complete the hourglassSum function below.
# https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
def hourglassSum(arr):
    if len(arr) == 0:
        return 0

    arr_sum = -9999
    row_num = len(arr) - 1
    col_num = len(arr[0]) - 1

    row = 0
    col = 0
    temp_sum = 0

    while row <= (row_num - 2):
        while col <= (col_num - 2):
            temp_sum = sum(arr[row][col:col + 3]) + \
                       arr[row + 1][col + 1] + \
                       sum(arr[row + 2][col:col + 3])

            if temp_sum > arr_sum:
                arr_sum = temp_sum

            temp_sum = 0
            col += 1
        col = 0
        row += 1

    return arr_sum