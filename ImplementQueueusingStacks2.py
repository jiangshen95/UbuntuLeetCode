class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._in = []
        self._out = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self._in = [x] + self._in

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        self.peek()
        return self._out.pop(0)

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if len(self._out) == 0:
            while len(self._in) > 0:
                self._out = [self._in.pop(0)] + self._out
        return self._out[0]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self._in) == 0 and len(self._out) == 0
        
if __name__ == '__main__':
    queue = MyQueue()
    queue.push(1)
    queue.push(2)
    print(queue.pop())
    print(queue.peek())
    print(queue.empty())
