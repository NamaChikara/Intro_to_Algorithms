class Stack:

    def __init__(self):
        self.items = []

    def size(self):
        return len(self.items)

    def is_empty(self):
        return self.size() == 0

    def push(self, item):
        self.items.append(item)

    def peek(self):
        item = []
        if not self.is_empty():
            item = self.items[self.size() - 1]
        return item

    def pop(self):
        item = self.peek()
        self.items = self.items[0:self.size() - 1]
        return item

