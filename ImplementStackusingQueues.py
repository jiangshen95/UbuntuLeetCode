import collections

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = collections.deque()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        size = len(self.stack)
        self.stack.append(x)
        for i in range(size):
            self.stack.append(self.stack.popleft())

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.stack.popleft()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.stack[0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.stack) == 0

if __name__ == '__main__':
    stack = MyStack()
    stack.push(1)
    stack.push(2)
    print(stack.pop())
    print(stack.top())
