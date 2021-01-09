import sys

N = int(sys.stdin.readline().rstrip())
lst = []

for i in range(N):
    nInput = sys.stdin.readline().rstrip()
    if nInput[:4] == "push":
        lst.append(int(nInput[5:]))
    elif nInput == "pop":
        if len(lst) == 0:
            print(-1)
        else:
            print(lst.pop())
    elif nInput == "size":
        print(len(lst))
    elif nInput == "empty":
        if len(lst) == 0:
            print(1)
        else:
            print(0)
    else:
        if len(lst) == 0:
            print(-1)
        else:
            print(lst[-1])
