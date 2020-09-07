from Python.Structures.Stack import Stack


def dec_to_binary(x):
    # Return binary representation of base 10 (decimal) number.

    exponents = Stack()

    while x > 0:
        remainder = x % 2
        exponents.push(remainder)
        x = int(x / 2)

    binary = ''

    while not exponents.is_empty():
        binary += str(exponents.pop())

    return binary
