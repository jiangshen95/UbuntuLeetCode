class Solution:
    def findMinArrowShots(self, points) -> int:
        count, end = 0, -float('inf')
        points.sort(key=lambda x: x[1])
        for point in points:
            if point[0] > end:
                end = point[1]
                count += 1
        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    points = [[nums[i], nums[i + 1]] for i in range(0, len(nums), 2)]
    solution = Solution()
    print(solution.findMinArrowShots(points))
