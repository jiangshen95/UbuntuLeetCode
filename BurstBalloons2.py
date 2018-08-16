class Solution:
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def burst(left, right):
            if left > right:
                return 0
            if dp[left][right]:
                return dp[left][right]
            for i in range(left, right + 1):
                dp[left][right] = max(dp[left][right], burst(left, i - 1) + burst(i + 1, right) +
                                      nums[i] * nums[left - 1] * nums[right + 1])
            return dp[left][right]

        n = len(nums)
        if n == 0:
            return 0
        dp = [[0 for _ in range(n + 2)] for _ in range(n + 2)]
        nums = [1] + nums + [1]
        return burst(1, n)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.maxCoins(nums))
