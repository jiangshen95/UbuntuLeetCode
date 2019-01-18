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
        points = [(interval.start, 1, i) for i, interval in enumerate(intervals)]
        points += [(interval.end, 0, i) for i, interval in enumerate(intervals)]
        points.sort()

        preIndexs = []
        result = [-1] * len(intervals)
        for point in points:
            if point[1] == 1:
                for index in preIndexs:
                    result[index] = point[2]
                preIndexs.clear()
            else:
                preIndexs.append(point[2])
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    intervals = []
    for i in range(0, len(nums), 2):
        intervals.append(Interval(nums[i], nums[i + 1]))
    solution = Solution()
    print(solution.findRightInterval(intervals))
