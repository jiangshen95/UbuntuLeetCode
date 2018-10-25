class Solution:
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 1 2 3 4 5 ... n  结果是i  翻转之后 结果是n + 1 - i（第i个）
        return 1 if n == 1 else 2 * (1 + n // 2 - self.lastRemaining(n // 2))


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lastRemaining(n))
