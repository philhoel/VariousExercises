from Week1 import *


def test_less_than():

    t = [1, 4, 3, 5, 7, 2, 3]
    n = 4
    expected = [1, 3, 2, 3]
    new_lst = less_than(t, n)
    assert expected == new_lst


def test_count_chars():

    example = "Hello, world!"
    expected = {'h': 1, 'e': 1, 'l': 3, 'o': 2,
                'w': 1, 'r': 1, 'd': 1, ',': 1, '!': 1, ' ': 1}

    computed = count_chars(example)

    assert computed == expected


def test_factorize():

    expected1 = [1]
    expected2 = [2, 5]
    expected3 = [11, 53]

    computed1 = factorize(1)
    computed2 = factorize(10)
    computed3 = factorize(583)

    assert computed1 == expected1
    assert computed2 == expected2
    assert computed3 == expected3
