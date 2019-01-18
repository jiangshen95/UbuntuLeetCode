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
        m = [(interval, i) for i, interval in enumerate(intervals)]
        result = [-1] * len(intervals)
        m.sort(key=lambda a: a[0].start)
        for i in range(len(m)):
            for j in range(i, len(m)):
                if m[j][0].start >= m[i][0].end:
                    result[m[i][1]] = m[j][1]
                    break
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    intervals = []
    for i in range(0, len(nums), 2):
        intervals.append(Interval(nums[i], nums[i + 1]))
    solution = Solution()
    print(solution.findRightInterval(intervals))
