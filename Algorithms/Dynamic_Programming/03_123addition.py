# Integer 4 can be expressed as a sum of 1s, 2s, and 3s 
# in seven different ways as follows:
# 
# 1+1+1+1,
# 1+1+2,
# 1+2+1,
# 2+1+1,
# 2+2,
# 1+3, and
# 3+1.
# 
# Write a program that determines the number of ways 
# in which a given integer can be expressed as a sum of 1s, 2s, and 3s. 
# You may assume that the integer is positive and less than 11.

iternum = int(input())

count = [0,1,2,4]
for _ in range(4, 12):
    count.append(sum(count[-3:]))

for _ in range(iternum):
    N = int(input())
    print(count[N])