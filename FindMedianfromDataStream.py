from heapq import *

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.large = []
        self.small = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        heappush(self.small, num)
        heappush(self.large, -heappop(self.small))
        if len(self.small) < len(self.large):
            heappush(self.small, -heappop(self.large))

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.small) == len(self.large):
            return (self.small[0] - self.large[0]) * 0.5
        else:
            return self.small[0]


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