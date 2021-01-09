
# Initial approach from Top to bottom

# N = int(input())
# count = 0
# while N != 1:
#     if (N % 3) == 0:
#         N /= 3
#         count += 1

#     elif ((N-1) % 3) == 0:
#         N = (N-1) / 3
#         count += 2

#     elif (N % 2) == 0:
#         N /= 2
#         count += 1

#     else:
#         N -= 1
#         count += 1


# print(count)

# to find fastest way to 1, work from bottom to up
N = int(input())

count = [0] * (N+1)
for i in range(2, N+1):
    count[i] = count[i-1] + 1
    if (i % 2) == 0:
        count[i] = min(count[i], count[int(i/2)]+1)
    if (i % 3) == 0:
        count[i] = min(count[i], count[int(i/3)]+1)

# print(count)
print(count[N])
