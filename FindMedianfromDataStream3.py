from heapq import *

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = None, [], []
        self.i = 1

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        heappush(self.data[self.i], -heappushpop(self.data[-self.i], -self.i * num))
        self.i *= -1

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.data[1]) == len(self.data[-1]):
            return (self.data[1][0] - self.data[-1][0]) * 0.5
        else:
            return self.data[1][0]

if __name__ == '__main__':
    finder = MedianFinder()
    # finder.addNum(1)
    # finder.addNum(2)
    # print(finder.findMedian())
    # finder.addNum(3)
    # print(finder.findMedian())
    finder.addNum(-1)
    print(finder.findMedian())
    finder.addNum(-2)
    print(finder.findMedian())
    finder.addNum(-3)
    print(finder.findMedian())
    finder.addNum(-4)
    print(finder.findMedian())
    finder.addNum(-5)
    print(finder.findMedian())