class Solution:
    def findMinArrowShots(self, points) -> int:
        if not points:
            return 0
        points.sort()
        print(points)
        count = 1
        end = points[0][1]
        for i in range(1, len(points)):
            if points[i][0] <= end:
                end = min(end, points[i][1])
            else:
                count += 1
                end = points[i][1]
        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    points = [[nums[i], nums[i + 1]] for i in range(0, len(nums), 2)]
    solution = Solution()
    print(solution.findMinArrowShots(points))
