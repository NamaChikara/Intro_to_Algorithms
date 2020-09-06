from Python.Structures.Stack import Stack


def check_parens(x):
    # Read a string from left to right and decide whether left and right parentheses are balanced.

    stack = Stack.Stack()
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

