# Complete the minimumBribes function below.
# https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
def minimumBribes(q):
    nPlus = 0
    Chaos = False
    Done = len(q) < 2 # finish if len(q) is less than 2
    for i, original_position in enumerate(q):
        if original_position > i + 3:  # +1 for 0 based and +2 for maximum
            Chaos = True
    while not Done and not Chaos:
        Done = True # checks whether q is already ordered
        for i in range(len(q) - 1):
            if q[i] > q[i + 1]:
                Done = False
                q[i], q[i+1] = q[i+1], q[i]
                nPlus += 1
    if Chaos:
        print("Too chaotic")
    else:
        print(nPlus)



"""
   bribes = 0
    # make a copy of q to keep record of chaotic ones
    p = q.copy()

    for j in range(len(q) - 1):

        # using p, determine whether chaotic
        if p[j] > (j + 1):
            if p[j] - (j + 1) >= 3:
                print("Too chaotic")
                return

        # By bubble sorting the actual q, count how many swaps needed
        for k in range(len(q) - 1):
            if q[k] > q[k + 1]:
                q[k], q[k + 1] = q[k + 1], q[k]
                bribes += 1

    print(bribes)
    return

"""