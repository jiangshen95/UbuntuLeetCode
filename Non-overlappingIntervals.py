class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if not intervals:
            return 0
        intervals.sort(key=lambda interval: interval.end)
        end = intervals[0].end
        count = 0
        for interval in intervals[1:]:
            if interval.start >= end:
                end = interval.end
            else:
                count += 1
        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    intervals = []
    for i in range(0, len(nums), 2):
        intervals.append(Interval(nums[i], nums[i + 1]))
    solution = Solution()
    print(solution.eraseOverlapIntervals(intervals))
