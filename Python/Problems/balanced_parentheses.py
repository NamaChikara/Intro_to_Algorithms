from Python.Structures.Stack import Stack


def parens_matched(x):
    # Read a string from left to right and decide whether left and right parentheses are balanced.

    stack = Stack()
    matched = True

    for char in x:
        if char == '(':
            stack.push(0)
        elif char == ')':
            popped = stack.pop()
            if popped == []:
                matched = False
                break

    return matched and stack.size() == 0

