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
        def binarySearch(intervals, l, r, val):
            while l <= r:
                mid = l + (r - l) // 2
                if val > intervals[mid].end:
                    l = mid + 1
                elif val < intervals[mid].start:
                    r = mid - 1
                else:
                    return mid
            return r

        if not self.intervals:
            self.intervals.append(Interval(val, val))
        else:
            index = binarySearch(self.intervals, 0, len(self.intervals) - 1, val)
            if index == -1:
                if self.intervals[0].start - 1 == val:
                    self.intervals[0].start -= 1
                elif self.intervals[0].start > val:
                    self.intervals = [Interval(val, val)] + self.intervals
            elif index == len(self.intervals) - 1:
                if val == self.intervals[-1].end + 1:
                    self.intervals[-1].end += 1
                elif val > self.intervals[-1].end:
                    self.intervals.append(Interval(val, val))
            elif self.intervals[index].end + 1 == val and val + 1 == self.intervals[index + 1].start:
                self.intervals[index].end = self.intervals[index + 1].end
                self.intervals.pop(index + 1)
            elif self.intervals[index].end + 1 == val:
                self.intervals[index].end += 1
            elif self.intervals[index + 1].start - 1 == val:
                self.intervals[index + 1].start -= 1
            elif self.intervals[index].end < val < self.intervals[index + 1].start:
                self.intervals.insert(index + 1, Interval(val, val))

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        return self.intervals


if __name__ == '__main__':
    summary = SummaryRanges()
    num = int(input())
    while num != -1:
        summary.addNum(num)
        for interval in summary.getIntervals():
            print("%d  %d" % (interval.start, interval.end))
        num = int(input())
