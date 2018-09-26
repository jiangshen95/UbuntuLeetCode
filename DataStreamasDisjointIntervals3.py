import heapq


class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class SummaryRanges:

    def __init__(self):
        self.intervals = []

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        if val not in [x[0] for x in self.intervals]:
            heapq.heappush(self.intervals, (val, Interval(val, val)))

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        stack = []
        while self.intervals:
            idx, cur = heapq.heappop(self.intervals)
            if not stack:
                stack.append((idx, cur))
            else:
                _, pre = stack[-1]
                if pre.end + 1 >= cur.start:
                    pre.end = max(pre.end, cur.end)
                else:
                    stack.append((idx, cur))
        self.intervals = stack
        return list(map(lambda x: x[1], stack))


if __name__ == '__main__':
    summary = SummaryRanges()
    num = int(input())
    while num != -1:
        summary.addNum(num)
        for interval in summary.getIntervals():
            print("%d  %d" % (interval.start, interval.end))
        num = int(input())
