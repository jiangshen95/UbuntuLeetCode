class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        result = 0
        for i in points:
            m = {}
            for j in points:
                a, b = i[0] - j[0], i[1] - j[1]
                m[a * a + b * b] = m.get(a * a + b * b, 0) + 1
            for key, val in m.items():
                result += val * (val - 1)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    points = [[nums[i], nums[i + 1]] for i in range(0, len(nums), 2)]
    print(points)
    solution = Solution()
    print(solution.numberOfBoomerangs(points))
