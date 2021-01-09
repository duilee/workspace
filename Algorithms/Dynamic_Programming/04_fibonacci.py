# calculate how many fibonacci(0) and fibonacci(1)
# are called in the recursion

# def fibonacci(n):
#     if n == 0:
#         return 100
#     elif n == 1:
#         return 1
#     else:
#         return fibonacci(n-1) + fibonacci(n-2)

zeros = [1,0,1] + [0]*38
ones = [0,1,1] + [0]*38

for i in range(3, 41):
    zeros[i] = zeros[i-1] + zeros[i-2]
    ones[i] = ones[i-1] + ones[i-2]

internum = int(input())

for _ in range(internum):
    N = int(input())
    print(zeros[N], ones[N])
