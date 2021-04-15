# Complete the substrCount function below.
# https://www.hackerrank.com/challenges/special-palindrome-again
def substrCount(n, s):
    count = 0
    for i in range(n):
        count += 1
        right = i + 1
        left = i - 1

        loop = True
        while right < n and loop:
            if s[i] == s[right]:
                count += 1
                right += 1
            else:
                loop = False

        right = i + 1
        loop = True
        while left >= 0 and right < n and loop:
            if s[left] == s[right] and s[left] != s[i]:
                if i - left == 1:
                    count += 1
                    left -= 1
                    right += 1
                else:
                    if s[left] == s[left + 1]:
                        count += 1
                        left -= 1
                        right += 1
                    else:
                        loop = False
            else:
                loop = False

    return count

"""
def substrCount(n, s):
    l = []
    count = 0
    cur = None

# 1st pass
    for i in range(n):
        if s[i] == cur:
            count += 1
        else:
            if cur is not None:
                l.append((cur, count))
            cur = s[i]
            count = 1
    l.append((cur, count))

    ans = 0
		
# 2nd pass
    for i in l:
        ans += (i[1] * (i[1] + 1)) // 2

# 3rd pass
    for i in range(1, len(l) - 1):
        if l[i - 1][0] == l[i + 1][0] and l[i][1] == 1:
            ans += min(l[i - 1][1], l[i + 1][1])

    return ans
"""
