# https://www.hackerrank.com/challenges/frequency-queries
# Complete the freqQuery function below.
def freqQuery(queries):
    freq_dict = {}
    output = []

    for query in queries:
        if query[0] == 1:
            if query[1] in freq_dict:
                freq_dict[query[1]] += 1
            else:
                freq_dict[query[1]] = 1
        elif query[0] == 2:
            if query[1] in freq_dict and freq_dict[query[1]] > 0:
                freq_dict[query[1]] -= 1
        else:
            exist_bool = False
            for a_key in freq_dict:
                if freq_dict[a_key] == query[1]:
                    exist_bool = True
                    break
            if exist_bool:
                output.append(1)
            else:
                output.append(0)

    return output

"""
def freqQuery(queries):

freq = Counter()

cnt = Counter()

arr = []

for q in queries:
    if q[0]==1:
        cnt[freq[q[1]]]-=1
        freq[q[1]]+=1
        cnt[freq[q[1]]]+=1

    elif q[0]==2:
        if freq[q[1]]>0:
            cnt[freq[q[1]]]-=1
            freq[q[1]]-=1
            cnt[freq[q[1]]]+=1

    else:
        if cnt[q[1]]>0:
            arr.append(1)
        else:
            arr.append(0)

return arr
"""