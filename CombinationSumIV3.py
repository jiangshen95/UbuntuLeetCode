class Solution:
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def helper(x):
            if x < 0:
                return 0
            if dp[x] != -1:
                return dp[x]
            count = 0
            for num in nums:
                if x >= num:
                    count += helper(x - num)
            dp[x] = count
            return count
        dp = [-1] * (target + 1)
        dp[0] = 1
        return helper(target)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    target = int(input())
    solution = Solution()
    print(solution.combinationSum4(nums, target))
