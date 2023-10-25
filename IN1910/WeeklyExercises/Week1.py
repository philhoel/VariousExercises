
import numpy as np


def less_than(original: list[int], n: int) -> list[int]:
    return [x for x in original if x < n]


def deck_of_cards() -> list[(int, chr)]:

    deck = [0]*52
    for i in range(1, 14):
        deck[i-1] = (i, 'C')
        deck[i+12] = (i, 'D')
        deck[i+25] = (i, 'H')
        deck[i+38] = (i, 'S')

    np.random.shuffle(deck)

    return deck


def pick_card(deck: list[(int, chr)]) -> list[(int, chr)]:
    return [card for card in deck[:13]]


deck = deck_of_cards()
hand = pick_card(deck)
print(sorted(hand, key=lambda x: (x[1], x[0])))


def count_chars(s: str) -> dict:
    count_dict = {}
    for char in s:
        if char.lower() in count_dict.keys():
            count_dict[char.lower()] += 1
        else:
            count_dict[char.lower()] = 1

    return count_dict


example = "Hello, world!"
new_lst = []
for char, count in count_chars(example).items():
    new_lst.append((char, count))

print(sorted(new_lst, key=lambda x: -x[1]))
print()
new_lst2 = []
example2 = "Thiss iss a sstring with many ssss"
for char, count in count_chars(example2).items():
    new_lst2.append((char, count))

print(sorted(new_lst2, key=lambda x: -x[1]))


def factorize(num):

    if num == 1:
        return [1]

    if num == 2:
        return [2]

    lst = []
    for i in range(2, num+1):
        if num % i == 0:
            lst.append(i)
            new_lst = factorize_rec(num, int(num/i), lst)
            break

    return new_lst


def factorize_rec(original, num, lst):

    if len(lst) > 1 and np.prod(lst) == original:
        return lst

    for i in range(2, num+1):
        if num % i == 0:
            lst.append(i)
            return factorize_rec(original, int(num/i), lst)


l = factorize(583)
print(l)
