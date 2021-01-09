import sys

N = int(sys.stdin.readline().rstrip())

for i in range(N):
    nInput = sys.stdin.readline().rstrip()
    num_rightp = 0
    num_leftp = 0

    # if Odd, then not a valid parenthesis string

    if (len(nInput) % 2) == 1:
        print("NO")
        continue

    for j in range(len(nInput)):
        if nInput[j] == '(':
            num_leftp += 1
        else:
            num_rightp += 1

        if num_leftp < num_rightp:
            break

    if num_leftp == num_rightp:
        print("YES")
    else:
        print("NO")