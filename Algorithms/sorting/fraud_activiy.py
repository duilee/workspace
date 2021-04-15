"""
# works, but takes too long
# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    count = 0
    for i in range(0, len(expenditure)-d):
        trails = expenditure[i:i+d]
        trails.sort()
        if d % 2 == 1:
            median = trails[int((len(trails)-1)/2)]
        else:
            median = (trails[int(len(trails) / 2)] + trails[int((len(trails) / 2) - 1)]) / 2

        if expenditure[i+d] >= (median * 2):
            count += 1
"""

# https://www.hackerrank.com/challenges/fraudulent-activity-notifications
# smarter solutoin using freqs table
# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    freqs = {}
    counts = 0

    def find(idx):
        total_count = 0
        for i in range(201):
            if i in freqs:
                total_count += freqs[i]
            if total_count >= idx:
                return i

    for i in range(len(expenditure) - 1):
        if expenditure[i] in freqs:
            freqs[expenditure[i]] += 1
        else:
            freqs[expenditure[i]] = 1

        if i >= d - 1:
            if d % 2 == 1:
                median = find(d / 2)
            else:
                median = (find((d / 2)) + find((d / 2) + 1)) / 2

            if expenditure[i + 1] >= (median * 2):
                counts += 1

            freqs[expenditure[i - d + 1]] -= 1

    return counts