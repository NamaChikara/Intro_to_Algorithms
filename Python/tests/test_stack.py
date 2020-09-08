from structures.stack import Stack


def test_initialization():
    my_stack = Stack()
    assert my_stack.items == []
    assert my_stack.size() == 0
    assert my_stack.is_empty()


def test_push():
    my_stack = Stack()
    my_stack.push(0)
    my_stack.push(1)
    assert my_stack.items == [0, 1]
    assert my_stack.size() == 2
    assert my_stack.is_empty() is False


def test_peek():
    my_stack = Stack()
    my_stack.push(0)
    my_stack.push(1)
    assert my_stack.peek() == 1


def test_pop():
    my_stack = Stack()
    my_stack.push(0)
    my_stack.push(1)
    popped = my_stack.pop()
    assert popped == 1
    assert my_stack.peek() == 0
