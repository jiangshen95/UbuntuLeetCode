class Solution:
    def find132pattern(self, nums) -> bool:
        n = len(nums)
        mn = nums.copy()
        for i in range(1, n, 1):
            mn[i] = min(mn[i - 1], mn[i])
        dp = [-1] * n
        for i in range(n):
            j = i - 1
            while j != -1 and nums[j] <= nums[i]:
                j = dp[j]
            dp[i] = j
        for i in range(2, n):
            j = dp[i]
            if j > 0 and mn[j - 1] < nums[i]:
                return True
        return False


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.find132pattern(nums))
