from Week2 import *


def test_is_prime():

    primes = [2, 3, 4, 5, 7, 9, 10, 15, 17, 23, 50, 97]
    expected = [True, True, False, True, True,
                False, False, False, True, True, False, True]

    for index, p in enumerate(primes):
        assert is_prime(p) == expected[index]


def test_bubble_sort():

    expected1 = [1]
    expected2 = [1, 2, 5, 7, 8]
    expected3 = [1, 1, 1, 1]

    computed1 = bubble_sort([1])
    computed2 = bubble_sort([2, 8, 7, 1, 5])
    computed3 = bubble_sort([1, 1, 1, 1])

    assert [] == bubble_sort([])
    assert computed1 == expected1
    assert computed2 == expected2
    assert computed3 == expected3
