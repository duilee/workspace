# Complete the luckBalance function below.
# www.hackerrank.com/challenges/luck-balance
def luckBalance(k, contests):
    total_sum = 0
    imp_list = []
    for luck, importance in contests:
        if importance == 0:
            total_sum += luck
        else:
            imp_list.append(luck)

    imp_list.sort()
    if k > 0:
        total_sum += sum(imp_list[-k:])
        total_sum -= sum(imp_list[:-k])
    else:
        total_sum -= sum(imp_list)

    return total_sum