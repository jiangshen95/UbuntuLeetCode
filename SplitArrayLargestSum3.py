class Solution:
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        n = len(nums)
        INT_MAX = (1 << 31) - 1;
        dp = [0] * n
        sums = [0] * (n + 1)
        for i in range(n):
            sums[i + 1] = sums[i] + nums[i]

        for i in range(n):
            dp[i] = sums[n] - sums[i]

        for i in range(1, m):
            for j in range(0, n - i):
                dp[j] = INT_MAX
                for k in range(j + 1, n - i + 1):
                    t = max(dp[k], sums[k] - sums[j])
                    if t <= dp[j]:
                        dp[j] = t
                    else:
                        break
        return dp[0]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    m = int(input())
    solution = Solution()
    print(solution.splitArray(nums, m))
