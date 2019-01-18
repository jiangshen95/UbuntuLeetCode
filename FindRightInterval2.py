class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        import bisect
        m = [(interval.start, i) for i, interval in enumerate(intervals)]
        m.sort()
        result = []
        for interval in intervals:
            r = bisect.bisect_left(m, (interval.end,))
            result.append(m[r][1] if r < len(m) else -1)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    intervals = []
    for i in range(0, len(nums), 2):
        intervals.append(Interval(nums[i], nums[i + 1]))
    solution = Solution()
    print(solution.findRightInterval(intervals))
