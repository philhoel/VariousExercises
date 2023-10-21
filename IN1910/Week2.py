import numpy as np


def is_prime(num: int) -> bool:

    if num == 2 or num == 1:
        return True

    for i in range(2, num):
        # print(f"num: {num}")
        # print(f"i: {i}")
        # print(f"num % i: {num % i}")
        if num % i == 0:
            return False

    return True


primes = [2, 3, 4, 5, 7, 9, 10, 15, 17, 23, 50, 97]
for p in primes:
    print(is_prime(p))


def bubble_sort(l: list) -> list:

    n = len(l)
    if n < 2:
        return l

    while True:
        swapped = False
        for i in range(1, n):
            if l[i-1] > l[i]:
                l[i-1], l[i] = l[i], l[i-1]
                swapped = True

        if not swapped:
            break

    return l


l = [3, 1, 4, 5, 2, 10, 7]
print(sorted(l))
print(bubble_sort(l))
