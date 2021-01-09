N = int(input())

# def gettiles(n):
#     if n == 0:
#         return 1
#     elif n == 1:
#         return 2
#     else:
#         return gettiles(n-1) + gettiles(n-2)

# print(gettiles(N)/10007)

x = [0,1,2] + [0]*998

for i in range(3, N+1):
    x[i] = x[i-1] + x[i-2]

print(x[N]/10007)