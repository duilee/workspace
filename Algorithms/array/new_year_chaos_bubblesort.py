# Complete the minimumBribes function below.
# https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
def minimumBribes(q):
    bribes = 0
    p = q.copy()

    for j in range(len(q) - 1):

        if p[j] > (j + 1):
            if p[j] - (j + 1) >= 3:
                print("Too chaotic")
                return

        for k in range(len(q) - 1):
            if q[k] > q[k + 1]:
                q[k], q[k + 1] = q[k + 1], q[k]
                bribes += 1

    print(bribes)
    return

"""
    nPlus = 0
    Chaos = False
    Done = n < 2
    for i,original_position in enumerate(q):
        if original_position > i+3: # +1 for 0 based and +2 for maximum
            Chaos = True
    while not Done and not Chaos:
        Done = True
        for i in range(len(q)-1):
            if q[i] > q[i+1]:
                Done = False
                qtmp = q[i]
                q[i] = q[i+1]
                q[i+1] = qtmp
                nPlus += 1
    if Chaos:
        print ("Too chaotic")
    else:
        print (nPlus)

"""