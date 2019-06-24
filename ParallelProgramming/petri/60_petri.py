#!/usr/bin/env python3

holes_count = 3
transitions_count = 3


def can_transit(U, I):
    for k in range(holes_count):
        if U[k] < I[k]:
            return False
    return True


def transit(I, O, U):
    for j in range(holes_count):
        U[j] = U[j] - I[j] + O[j]
    return U


def main(char):
    I = [
        [122, 0, 0],
        [1, 0, 1],
        [1, 0, 0],
    ]
    O = [
        [0, 97, 0],
        [2, 0, 0],
        [0, 1, 0],
    ]
    U = [ord(char), 0, 1]

    for i in range(transitions_count):
        while can_transit(U, I[i]):
            U = transit(I[i], O[i], U)

    return chr(U[1])


char = input("Enter one character: ")
assert len(char) == 1, "Enter exactly one character"
result = main(char)
print(result)
