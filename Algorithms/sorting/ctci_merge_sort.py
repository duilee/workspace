count = 0

def mergesort2(A):
    global count
    if len(A) > 1:
        n = len(A)
        m = int(n/2)
        L = A[:m]
        R = A[m:n]

        mergesort2(L)
        mergesort2(R)

        i = 0
        j = 0
        k = 0
        n1 = m
        n2 = n-m

        while i < n1 and j < n2:
            if L[i] <= R[j]:
                A[k] = L[i]
                i += 1
                k += 1
            else:
                A[k] = R[j]
                j += 1
                k += 1
                count += n1-i

        while i < n1: # fill in the rest if left
            A[k] = L[i]
            i+=1
            k+=1
        while j < n2: # fill in the rest if left
            A[k] = R[j]
            j+=1
            k+=1


# Complete the countInversions function below.
def countInversions(arr):
    global count
    count = 0
    mergesort2(arr)
    return count