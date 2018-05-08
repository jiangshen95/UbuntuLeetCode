import collections

class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = collections.deque()
        self._top = 0

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        self.stack.append(x)
        self._top = x

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        size = len(self.stack)
        for i in range(size - 1):
            self._top = self.stack.popleft()
            self.stack.append(self._top)
        return self.stack.popleft()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self._top

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
