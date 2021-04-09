def countSwaps(a):
    count = 0

    for i in range(len(a)):
        swap = False
        for j in range(len(a) - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swap = True
                count += 1
        if swap == False:
            break

    print(f'Array is sorted in {count} swaps.')
    print(f'First Element: {a[0]}')
    print(f'Last Element: {a[-1]}')
    return