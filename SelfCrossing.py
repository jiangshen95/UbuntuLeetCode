class Solution:
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        for i in range(3, len(x)):
            if x[i] >= x[i - 2] and x[i - 1] <= x[i - 3]:
                return True
            if i == 4 and x[i - 1] == x[i - 3] and x[i] + x[i - 4] >= x[i - 2]:
                return True
            if i >= 5 and x[i - 4] <= x[i - 2] <= x[i] + x[i - 4] and x[i - 1] <= x[i - 3] <= x[i - 1] + x[i - 5]:
                return True
        return False


if __name__ == '__main__':
    x = [int(_) for _ in input().split()]
    solution = Solution()
    print(solution.isSelfCrossing(x))
